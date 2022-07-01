<div id="top"></div>

<br />
<div align="center">
  <a href="https://github.com/Jax-Core/ValliStart">
    <img src="https://cdn.discordapp.com/attachments/875630623853793283/977856719055114250/ValliStart3.png" alt="Logo" width="200" height="200">
  </a>
  <h3 align="center">ValliStart</h3>
  <p align="center">
    A custom start menu to replace the default one.
    <br />
    <a href="https://www.deviantart.com/jaxoriginals/art/    ValliStart-Start-menu-replacement-893506095"><strong>More Info »</strong>
    </a>
    <br />
    <br />
    <a href="https://discord.gg/JmgehPSDD6">Report Bugs & Request Features</a>
  </p>
</div>

<p align="center">
  <img alt="Latest by date" src="https://img.shields.io/github/v/tag/Jax-Core/ValliStart?label=Version&style=for-the-badge" />
  <img alt="Releases" src="https://img.shields.io/github/downloads/Jax-Core/ValliStart/total?style=for-the-badge" />
  <img alt="Release date" src="https://img.shields.io/github/release-date/Jax-Core/ValliStart?label=Last%20Update&style=for-the-badge" />
  <img alt="Discord" src="https://img.shields.io/discord/880445067754610688?label=Discord%20server&style=for-the-badge" />
  <img alt="Github" src="https://img.shields.io/github/license/Jax-Core/ValliStart?style=for-the-badge" />
  
</p>

<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about">About</a>
    </li>
    <li>
      <a href="#Features">Features</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
        <li> <a href="#customization">Customization</a></li>
      </ul>
    </li>
    <li>
      <a href="#modules-setup">Modules Setup</a>
      <ul>
        <li><a href="#pinned-shortcuts">Pinned Shortcuts</a></li>
        <li><a href="#weather">Weather</a></li>
        <li><a href="#media-controls">Media Controls</a>
          <ul>
            <li><a href="#for-spotify">Spotify</a></li>
            <li><a href="#for-web-players">Web Players</a></li>
          </ul>
        </li>
      </ul>
    </li>
    <li> <a href="#help-and-credits">Help & Credits</a></li>
  </ol>
</details>

<!-- ABOUT THE PROJECT -->
## About

![ValliStart3](https://user-images.githubusercontent.com/80020581/169686772-4ffa8032-c98f-4af7-9805-4f6bcfd25d32.png)

ValliStart is a start menu replacement for Windows, with full customizability, interchangeable modules and more.

## Features

* Flawless Animations
* Full-fledged Control Center
* Custom Pinned Shortcuts
* Intergrated Media Controls
* Customizable Hotkeys
* Additional Modules like Weather Status

<p align="right">
    <b><a href="#top">↥ back to top</a></b>
</p>

<!-- INSTALLATION AND SETUP -->
## Getting Started

### Prerequisites
- **Windows 10** or above
- For older systems, **Powershell v5.1 or newer** is required. Upgrade powershell **[here](https://docs.microsoft.com/en-us/powershell/scripting/windows-powershell/install/installing-windows-powershell?view=powershell-7.2#upgrading-existing-windows-powershell)**!

### Installation 
**By Powershell CLI:**
Run the following command in Powershell (`win + r` -> `powershell.exe` / search)
```
$installSkin="ValliStart";Invoke-WebRequest -UseBasicParsing "https://raw.githubusercontent.com/Jax-Core/JaxCore/master/CoreInstaller.ps1" | Invoke-Expression
```
**By legacy [Rainmeter](https://www.rainmeter.net/) .rmskin installer:**
Download and run the `.rmskin` file from the latest release **[here](https://github.com/Jax-Core/ValliStart/releases/latest)**.
> Note:  If you find that the JaxCore option is red on the startup pop-up, please press the red button and Core will be installed automatically. Perchance this fails, you can manually install Core by downloading the `.rmskin` file from [JaxCore's official website.](https://jax-core.github.io/)
<br />
<br />

## Customization

ValliStart includes 6 color scheme presets. You enable them by just selecting them within the **Color Scheme** tab.
Furthermore, ValliStart also comes with 4 layout presets. You can enable them by just selecting them within the **Layout** tab:

![image](https://user-images.githubusercontent.com/80020581/156275153-104e47da-ef14-4b63-8809-a5058d15f417.png)

## Activation 
ValliStart can be activated in multiple ways:
#### Replacing the native windows button and key
You can launch ValliStart just like the start menu with the `Win` Key. Additionally, you can replace the windows button by:
- Creating a pseudo start button with core
1. Navigate to `JaxCore -> ValliStart -> General -> Setting: Customize how to activate ValliStart` and turn on override start button. 
2. Select a start orb name. The default is `Win11`. You can choose another one / add your own one in the orbs directory, and entering another start orb name.
3. Press the `Create` button above
4. Core should popup the explorer with shortcut `ValliStart.lnk` inside
5. Drag the shortcut to the taskbar
6. Now you have a pseudo start button on the taskbar! 
7. If you want to remove the stock start button: You can use [StartKiller](http://www.startkiller.com/) for Win10. There are no known ways of doing so on Windows 11.

- Using ValliStart's winblock function to create an overlay which overlaps the start button on your taskbar
1. Navigate to `JaxCore -> ValliStart -> General -> Setting: Customize how to activate ValliStart` and turn on override start button. 
2. Toggle `Setting: Display WinBlock element (legacy)` on
3. Switch `Setting: Win block behavior` to edit
4. Drag the winblocker to desired location
5. Switch `Setting: Win block behavior` to functional

#### Using a separate hotkey
You can also launch ValliStart with the hotkey of your choice. This does not support overriding the displayed window button on your taskbar.
1. Navigate to `JaxCore -> ValliStart -> General -> Setting: How should ValliStart behave?` and switch the option to `Separate module`
2. Change `Setting: Activation Hotkey`to your desired hotkey

<p align="right">
    <b><a href="#top">↥ back to top</a></b>
</p>

<!-- MODULES SETUP -->
# Modules Setup

Now that you've installed and setup ValliStart, let's begin setting up some modules it comes with!

## Pinned Shortcuts

### Choosing a module preset

If your ValliStart layout preset does not have the pinned shortcuts module enabled by default, follow the steps outlined below to enable it. However, if it is already enabled/selected, you can skip to configuring it.

1. Open Core and head over to the **Modules** section.
2. Select **ValliStart** from the list and proceed to the **Modules** tab.
3. Scroll all way to the bottom, find the module labelled **None** and click `Change`. Alternatively, you can also replace any other pre-existing module with the shortcut module.
4. Go to the **Shortcut Modules** tab and select a preset you like. You can choose from three presets; **WinRow11**, **DoubleRow**, and **SingleRow**.
    >  <img src ="https://imgur.com/JgHZTni.png" alt = "ref" width="378" height ="80">

### Configuring the preset

1. Open Core and head over to the **Modules** section.
2. Select **ValliStart** from the list and proceed to the **Modules** tab.
3. Open the settings for your currently enabled shortcuts module.
4. Click on one of the pre-existing shortcut's name.
5. Select the shortcut for the application to be pinned.

That's all there is to it. Your shortcuts will now be visible in the pinned applications section.

## Weather

1. Open Core and head over to the **Modules** section.
2. Select **ValliStart** from the list and proceed to the **Modules** tab.
3. Open the settings for the **Weather** module.
4. Click the green redirect button next to the `Configure weather settings in core's global settings` text.
    >  <img src ="https://imgur.com/WDatjK5.png" alt = "ref" width="755" height ="81">

5. Once the **Global Variables** configuration window opens, change the weather location to the location you want the weather status of.
    >  <img src ="https://imgur.com/ycI4Qp4.png" alt = "ref" width="867" height ="55">
6. Refresh ValliStart by deactivating and activating again using the toggle on the bottom left.

> **Note:** You can also alter other options like the temperature unit, the language the weather is shown in, and the time format when configuring the weather location on **Step 5**. Also, **if you're not sure what the API key is for, don't change or edit it.**

# Help and Credits

* Spicetify installation guide by [khanhas](https://github.com/khanhas).

* Join the [Core Community Discord Server](https://discord.gg/JmgehPSDD6) for more help.

<p align="right">
    <b><a href="#top">↥ back to top</a></b>
</p>
