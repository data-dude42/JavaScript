# IP Address Tracker

## Welcome! 👋

## Table of contents

- [Overview](#overview)
  - [The challenge](#the-challenge)
  - [How to setup the project](#how-to-setup-the-project)
  - [Screenshot](#screenshot)
  - [Links](#links)
- [My process](#my-process)
  - [Built with](#built-with)
  - [What I learned](#what-i-learned)
  - [Continued development](#continued-development)
  - [Useful resources](#useful-resources)
- [Author](#author)
- [Acknowledgments](#acknowledgments)

## Overview

### The challenge

Discover the location, timezone, and ISP of any IP address with the IP Address Tracker!

This webpage allows users to

- View the optimal layout for each page depending on their device's screen size.
- See hover states for all interactive elements on the page.
- Find their own IP address on the map on the initial page load.
  Users can also search for any IP addresses or domains and see the key information and location.

### How to setup the project

To set up the project locally, follow these steps:

1. Clone the repository using GitHub Desktop or Git Bash:
   ```bash
   git clone https://github.com/SartHak-0-Sach/IP-address-tracker_frontend_project.git
   ```
2. Open the project folder in your code editor.
3. Run the project using a live server extension or deploy it using Netlify, Vercel, or another web hosting and deployment service.

### Screenshot

![Design Preview](./design/active-states.jpg)

### Links

- Solution URL: [GitHub Repository](https://github.com/SartHak-0-Sach/IP-address-tracker_frontend_project)
- Live Site URL: [Live Site](https://ip-address-tracker-app-project.netlify.app/)

## My process

### Built with

- HTML5
- CSS3
- JavaScript
- Leaflet.js (for the map)
- IP Geolocation API (for fetching IP address details)

You will find all the required assets in the `/design` folder. The assets are already optimized.

There is also a `style-guide.md` file containing the information you'll need, such as color palette and fonts.

### What I learned

This project is great at understanding how to execute basic CSS features like flexbox, responsive layout using media queries for both desktop and mobile and all sizes in between as shown below-

```css
@media (max-width: 920px) {
    .info-field {
        font-size: .9rem;
    }
}

@media (max-width: 770px) {
    #ip-input {
        width: min(380px, 70%);
    }

    .info {
        width: 85vw;
    }
}

@media (max-width: 600px) {
    .top {
        height: 35vh;
        padding: .7rem;
    }

    .title {
        font-size: 1.5rem;
    }

    .info {
        width: 75vw;
        flex-direction: column;
        text-align: center;
        gap: 1.1rem;
        top: 12%;
    }

    .box {
        width: 100%;
        border: none;
    }
}
```

### Continued development

The continuously learning journey of a programmer never ends. This project made me realize that there are many concepts that I need to work upon including fundamentals like flex-box and its properties, to more complex concepts like working with fetch and async await in javascript. These areas are some that I think I need to work more upon in the upcoming future as they highlight some of the most significant regions of web development that are important for every developer to know of.

These key points mentioned here will help me grow accountable and consistent towards improving at writing good quality code and be a successful full stack developer one day.

**Happy coding!** ☺️🚀
