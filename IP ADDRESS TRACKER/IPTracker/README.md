# IP Address Tracker

## Description

A web app to search for any IP address or domain, displaying its location, timezone, and ISP on an interactive map.

Deployed on GoogleFireBase & here is the link: [IP Address Tracker (ip-tracker-7fcb4.web.app)](https://ip-tracker-7fcb4.web.app/)

## Features

- Search for IP address or domain
- Display IP address, location, timezone, and ISP
- Interactive map with Leaflet
- Error handling with modal dialog

## Technologies

- HTML5
- CSS3
- JavaScript
- Leaflet.js
- Font Awesome
- Google Fonts

## Usage

1. Clone the repo and navigate to the directory:
   ```sh
   git clone https://github.com/your-username/ip-address-tracker.git
   cd ip-address-tracker
   ```

# IP Address Tracker Script

## Description

This JavaScript file is the core functionality provider for the IP Address Tracker web application. It allows users to input an IP address or domain, fetches the relevant data, and displays it on an interactive map along with additional details such as location, timezone, and ISP. The script includes functionalities for error handling, displaying a loading indicator during data fetching, and maintaining a list of recent searches.

## Features

- **Fetch IP Information**: Retrieves IP address information including location, timezone, and ISP.
- **Interactive Map**: Utilizes Leaflet.js to display the IP address location on an interactive map.
- **Error Handling**: Displays errors in a modal dialog.
- **Loading Indicator**: Shows a loading indicator during data fetching.
- **Recent Searches**: Maintains and displays a list of recent IP searches.

## Implementation Details

### Main Functions

1. **renderResults(data)**

   - **Parameters**: `data` (Object) - The IP information fetched from the API.
   - **Description**: Updates the DOM elements with the IP information and centers the map on the provided location.
   - **Error Handling**: Throws an error if the `data` object contains an error.
2. **displayError(e)**

   - **Parameters**: `e` (Error/String) - The error to be displayed.
   - **Description**: Displays the error message in a modal dialog.
3. **showLoading()**

   - **Description**: Sets the display style of the loading indicator to `block`, making it visible.
4. **hideLoading()**

   - **Description**: Sets the display style of the loading indicator to `none`, hiding it.
5. **addToRecentSearches(data)**

   - **Parameters**: `data` (Object) - The IP information to be added to recent searches.
   - **Description**: Creates a clickable element with the IP information and appends it to the recent searches container. When clicked, it re-renders the results for that IP.

### Event Listeners

- **formEl.onsubmit**

  - **Description**: Prevents the default form submission behavior, shows the loading indicator, fetches IP information based on user input, handles the response or error, and resets the form.
- **closeBtn.onclick**

  - **Description**: Closes the modal dialog displaying error messages.

### Initialization

- Fetches and displays the user's current IP information on page load.

### Dependencies

- **Leaflet.js**: For rendering the interactive map. Loaded from a CDN.
- **ipapi.co**: API service used for fetching IP information.

## Usage

1. **Include the Script**

   - Ensure `script.js` is included in your HTML file:
     ```html
     <script src="script.js"></script>
     ```
2. **HTML Structure**

   - Ensure the following elements are present in your HTML, with the correct IDs and classes:
     ```html
     <form>
         <input type="text" id="ip-input">
         <button type="submit">Submit</button>
     </form>

     <div id="ip-info"></div>
     <div id="location-info"></div>
     <div id="timezone-info"></div>
     <div id="isp-info"></div>

     <dialog id="modal">
         <p id="error-message"></p>
         <button id="close-btn">Close</button>
     </dialog>

     <div id="map"></div>
     <div id="loading-indicator">Loading...</div>
     <div id="recent-searches"></div>
     ```
3. **Styles**

   - Customize styles for elements such as `#loading-indicator` and `.recent-search` in your CSS file to improve the UI.

### Example Usage

1. **Form Submission**

   - User enters an IP address or domain in the input field and submits the form.
   - The script fetches the data, displays it in the designated elements, updates the map, and logs the search in recent searches.
2. **Recent Searches**

   - Recent searches are displayed below the main form.
   - Clicking a recent search item re-renders the results for that IP address.

### Notes

- Ensure the API key for the map service is valid and has necessary permissions.
- Modify URLs and element references as needed to fit your specific use case.
