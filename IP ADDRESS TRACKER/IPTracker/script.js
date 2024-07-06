const formEl = document.querySelector('form');
const ipInputEl = document.getElementById('ip-input');
const ipEl = document.getElementById('ip-info');
const locationEl = document.getElementById('location-info');
const timezoneEl = document.getElementById('timezone-info');
const ispEl = document.getElementById('isp-info');

const modal = document.getElementById('modal');
const errorMsgEl = document.getElementById('error-message');
const closeBtn = document.getElementById('close-btn');
const loadingIndicator = document.createElement('div');
loadingIndicator.id = 'loading-indicator';
loadingIndicator.textContent = 'Loading...';
document.body.appendChild(loadingIndicator);

const recentSearchesEl = document.createElement('div');
recentSearchesEl.id = 'recent-searches';
document.body.appendChild(recentSearchesEl);

const map = L.map('map').setView([0, 0], 13);
const tileUrl = 'https://api.mapbox.com/styles/v1/{id}/tiles/{z}/{x}/{y}?access_token=pk.eyJ1Ijoia2V2ZXRpaDg2MSIsImEiOiJja2h4MzFxaG8wOW5pMzBsdGZ1NXFoeHh5In0.hw5mLyF4KWalDgcxAWrmuw';

L.tileLayer(tileUrl, {
    maxZoom: 18,
    attribution: false,
    id: 'mapbox/streets-v11',
    tileSize: 512,
    zoomOffset: -1
}).addTo(map);

const locationIcon = L.icon({
    iconUrl: 'images/icon-location.svg',
    iconSize: [35, 35],
    iconAnchor: [15, 15]
});

let marker = L.marker([0, 0], { icon: locationIcon }).addTo(map);

formEl.onsubmit = (e) => {
    e.preventDefault();
    showLoading();
    
    fetch(`https://ipapi.co/${ipInputEl.value}/json/`)
        .then(res => res.json())
        .then(data => {
            hideLoading();
            renderResults(data);
            addToRecentSearches(data);
        })
        .catch(error => {
            hideLoading();
            displayError(error);
        });
    
    e.target.reset();
}

fetch('https://ipapi.co/json/')
    .then(res => res.json())
    .then(data => {
        renderResults(data);
        addToRecentSearches(data);
    })
    .catch(error => displayError(error));

function renderResults(data) {
    if (data.error) {
        throw new Error(data.reason);
    }
    ipEl.textContent = data.ip;
    locationEl.textContent = `${data.city}, ${data.region}, ${data.country_name}`;
    timezoneEl.textContent = data.utc_offset ? 'UTC: ' + data.utc_offset.slice(0, 3) + ':' + data.utc_offset.slice(3) : data.timezone;
    ispEl.textContent = data.org;

    map.setView([data.latitude, data.longitude], 13);
    marker.setLatLng([data.latitude, data.longitude]);
    marker.bindPopup(`<b>${data.ip}</b>`).openPopup();
}

function displayError(e) {
    errorMsgEl.textContent = e.message || e;
    modal.showModal();
}

closeBtn.onclick = () => {
    modal.close();
}

function showLoading() {
    loadingIndicator.style.display = 'block';
}

function hideLoading() {
    loadingIndicator.style.display = 'none';
}

function addToRecentSearches(data) {
    const recentSearch = document.createElement('div');
    recentSearch.classList.add('recent-search');
    recentSearch.textContent = `${data.ip} - ${data.city}, ${data.region}, ${data.country_name}`;
    recentSearch.onclick = () => {
        ipInputEl.value = data.ip;
        renderResults(data);
    }
    recentSearchesEl.appendChild(recentSearch);
}
