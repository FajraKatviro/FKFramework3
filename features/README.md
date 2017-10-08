# Features section

This section designed for quick enabling/disabling framework features from project file

Add feature to FK variable to enable it (e.g. FK += imageset)

**AVAILABLE VALUES**

**mobile**

Feature designed to simplify project setup for mobile (iOS/Android) projects
iOS >= 7.0 required
android >= 4.4 recommended 
Use for fast & easy app icon & splash screen setup

Add variables to project file:
  * FK_IOS_PLIST - path/to/info.plist (you can use attached template)
  * FK_MOBILE_ICONS - path/to/icons/folder (separate for android & iOS)
  * FK_MOBILE_SPLASH_SCREENS - path/to/splashscreens/folder (separate for android & iOS)

You can use ImageManager to create icon & splash screen sets from given image


**deploy**

Simple multiplatform tool for install package creation.

Usage:

Check your qt project file contain following variables:
  * DESTDIR (Qt-defined)
  * VERSION (Qt-defined)
  * ICON (Qt-defined, path to *.icns for mac systems, or to 128x128 sized *.png for linux systems)
  * RC_ICONS (Qt-defined, path to icon image for windows systems, *.ico required)
  * QMAKE_TARGET_PRODUCT (defines package name)
  * QMAKE_TARGET_COMPANY (defines package maintainer)
  * LICENSE (path to license file, RTF required by WIX)
  * DEPLOY_BUILD_FOLDER (path where distributable package would build)
  * UPGRADE_CODE (GUID for app version, used by WIX, windows only)
  * SHORT_DESCRIPTION (description text, used by dpkg-deb, linux only)
  * LONG_DESCRIPTION (path to text file with description, used to create long description for dpkg-deb, linux only)

Work description:
First, calls qt deploy tool to add dependencies.
After that compresses all contents of DESTDIR to a single package.
All stuff and output files are placed in DEPLOY_BUILD_FOLDER.

Currently avaliable for platforms:
  - Windows (WIX required)
  - Mac OS (simple dmg only)
  - Ubuntu (dpkg, lintian, md5deep packages required)

Notes:

  1. Mac dmg does not contain any decorations and icon, this shoul be fixed later
  2. Linux deploy step is terrible and I need help to improve it. Also, lintian shows a lot of errors and it is disabled now. Please, contact me to deal with it.


**imageset**

Create special resources for screen-size-driven loading. The technic allows create screen-size-flexible UI. 
This feature invokes packageManager + packageGenerator and adds result to 'bundled' resources.
To use this feature you must set ART_FOLDER to your imageset folder (see packageManager for details) and ART_BUILD_FOLDER to some clean folder.


**content**

Invokes qt rcc compiler with no compression option and place resources to 'bundled' data location.
  Add required *.qrc files to CONTENT variable to use this feature 
  Add required files to RAW_CONTENT variable to deploy files 'as is', without rcc invocation


**modules**


**helpers**

Set of common-used headers
