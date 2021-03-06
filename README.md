# Kanan's New Mabinogi Mod
A reimagining of Kanan for Mabinogi written in C++ with many improvements.

## What's new
* Entirely written from the ground up in modern C++17. 
* Overall design was kept simple and *most* of it is commented so beginners can understand whats going on.
* Core memory hacking library is seperate from the Mabinogi specific portion and can be easily reused for other games.
* Includes an ingame UI to configure each mod.
* Includes a reusable Direct3D 9 hook.
* Includes a reusable DirectInput 8 hook.
* Intercepts windows messages sent to the game window.
* Reverse engineered game structures to allow for unique features such as entity viewing.
* Probably other things!

## Build requirements
* Visual Studio 2017

## Usage
Once the project has been built successfully in Release mode just run Loader.exe as an administrator. Loader.exe will automatically look for any instances of Mabinogi and load Kanan.dll into it. Press the INSERT key to toggle the UI.

## This project is still a work in progress
Once this project reaches (or approaches) feature parity with the original Kanan the URL for it will probably change to replace the original. I may periodically release official binaries for those who don't want to build the project themselves.

## Todo
* Add more patches and mods that were previously available in the original Kanan.
* Change the configuration system from `cpptoml` to something even lighter weight. Specifically, I don't like that it requires RTTI and uses exceptions (these are perfectly fine for most projects, but I dislike them in this project).

![Preview](preview.png)

## Original patch authors
kanan comes with more mods than are listed here. This is the list of patch authors who haven't directly contributed via GitHub's pull requests.
* Blade3575
    * Bitmap font
    * Elf lag
* Step29
    * NPC fast text
    * One click revive
    * Free indoor camera
    * Hide NPC curtains
    * Hide second title
    * No player zoom transparency
    * Mana tunnel lag fix
    * No skill rank up window
    * Windows appear faster
    * Uncapped auto production
    * Mini title menu (TitleOrganize)
    * Mute commerce imp (NoImp)
    * No render sky
* Rydian
    * Transformation mastery collect mode always enabled
    * No persistent fighter chain popup
    * Objects between camera and character do not become transparent
    * Hide main title

Many original patches/ideas came from the following projects:
* Fantasia
* MAMP
* JAP
* Gerent/GerentxNogi
* MNG
* Noginogi-Party

And to all the patchers that came before, and all that will come after.