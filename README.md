
<br />
<div align="center">
  <a href="https://github.com/Jax-Core/ValliStart">
    <img src="https://imgur.com/Dz6Zhwo.png" alt="Logo" width="80" height="80">
  </a>

<h3 align="center">ValliStart</h3>

  <p align="center">
    A custom start menu to replace the default one.
    <br />
    <a href="https://www.deviantart.com/jaxoriginals/art/ValliStart-Start-menu-replacement-893506095"><strong>More Info »</strong></a>
    <br />
    <br />
    <a href="https://discord.gg/JmgehPSDD6">Report Bugs & Request Features </a>
  </p>
</div>


<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about">About</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
        <li><a href="#media-controls">Media Controls</a></li>
      </ul>
    </li>
    <li>
    <a href="#setup">Modules Setup</a>
    <ul>
        <li><a href="#pinned-shortcuts">Pinned Shortcuts</a></li>
        <li><a href="#weather">Weather</a></li>
        <li><a href="#media-controls">Media Controls</a></li>
      </ul>
    </li>


  </ol>
</details>


## About

https://user-images.githubusercontent.com/80020581/135605193-383f546f-252e-4717-a38b-431e3d6fcdf8.mp4

ValliStart is a Rainmeter skin that replaces the standard Windows start menu with an animated, fancy control center. ValliStart includes 8 different color schemes as well as 15+ customization options for you to tweak and customize to your liking. **See the video linked above.**

## Features

* Built-in Windows Search Compatibility
* Flawless Animations
* Full-fledged Control Center
* Custom Pinned Shortcuts 
* Intergrated Media Controls
* Customizable Hotkeys
* Additional Modules like Weather Status

## Getting Started

### Prerequisites

- **Rainmeter v4.5 or newer.** Rainmeter can be installed by downloading the `.exe` file [from Rainmeter's official website.](https://www.rainmeter.net/).
- **JaxCore v40005.** JaxCore can be installed by downloading the `.rmskin` file from [JaxCore's official website.](https://jax-core.github.io/)

### Installation

Assuming you successfully downloaded and installed Rainmeter as well as JaxCore, you can now proceed to install ValliStart by following the steps below.

1. Download and run the `.rmskin` file for **ValliStart** from the official [JaxCore site](https://jax-core.github.io/) to install **ValliStart**.
2. Leave the installation settings at their defaults and click Install.
3. When the installation is finished, a startup pop-up should appear. Follow through the pop-up to finish installing ValliStart.

* Note:  If you find that the JaxCore option is red on the startup pop-up, please press the red button and Core will be installed automatically. Perchance this fails, you can manually install Core by downloading the `.rmskin` file from [JaxCore's official website.](https://jax-core.github.io/)

## Modules Setup

Now that you've installed and setup ValliStart, let's begin setting up some modules it comes with!

### Pinned Shortcuts

1. Open Core and head over to the **Modules** section.
2. Select **ValliStart** from the list and proceed to the **General** tab.
3. Under **Main Shortcuts** press the green button besides the `Select a file` text.
4. Select the shortcut for the application to be pinned.
5. Refresh ValliStart by deactivating and activating again using the toggle on the bottom left.

That's all there is to it. Your shortcuts will now be visible in the pinned applications section. **Please keep in mind that you can only pin up to 5 shortcuts at a time.**

### Weather

### Media Controls

#### Spotify:
For media controls to work with, you will have to setup and install **[Spicetify](https://spicetify.app/).** Follow the steps below to do so.

1. Open Powershell (Windows 10) or Windows Terminal (Windows 11) and run the commands that follow:
  ```
    Invoke-WebRequest -UseBasicParsing "https://raw.githubusercontent.com/khanhas/spicetify-cli/master/install.ps1" | Invoke-Expression

    spicetify

    spicetify config extensions webnowplaying.js
  ```
**If you only want to install `webnowplaying.js` without the custom themes, use the following command:**
  ```
    spicetify config inject_css 0 replace_colors 0
  ```
2. And finally, run the following command to save and apply all your changes:
  ```
    spicetify backup apply
  ```

Now, you can proceed to setting up the media controls. Simply, follow the stesp below:
1. 





## Help
- Join the [Core Community Discord Server](https://discord.gg/JmgehPSDD6) for more help.
