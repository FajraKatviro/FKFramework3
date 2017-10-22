# Features section

This section designed for quick enabling/disabling framework features from project file

Features are designed as separate qbs modules. Use Depends{ name: "FK"; submodules: [ --list of features-- ] } component to integrate it's functionality

Some submodules requires extra properties to be defined for product (See FKProduct for details)


**AVAILABLE QBS SUBMODULES**

**mobile**

Android - Not implemented yet
iOS - Not implemented yet


**deploy**

Simple multiplatform tool for package creation.
The feature copies Qt/QML dependencies and applies some other special requirements.
After that it creates platform-dependent installer


Avaliable platforms:
Windows + WIX installer - not implemented yet
MacOS   + dmg package   - not implemented yet
Ubuntu  + deb package   - not implemented yet


**imageset**

Create special resources for screen-size-driven loading. The technic allows create screen-size-flexible UI.
This feature invokes packageManager + packageGenerator and adds result to 'bundled' resources.

Not tested yet.


**content**

Basic pipeline for screen-size independent resources management.

Required product properties:
deployFolder

Accepted file tags:
*"fk.content"* - deploy resources to 'bundled' universal resources data location
*"fk.resource"* - use qt rcc compiler with no compression option before deployment

Optional variables:
FK.content.buildFolder - location where intermediate built resources will be places (default <buildDirectory>/builtResources)
FK.content.location - in-package deployed content location, usually relative to executable (default /constAppData/universalResources)
FK.content.sourceRoot - root path to resolve relative location of content. If undefined, content placed to the root of 'location' (default undefined)


**modules**

Not implemented yet


**helpers**

Set of common-used headers. See source files for details.

Required product properties:
name
version
maintainer

Optional variables:
FK.helpers.skipValidation - indicates if missing product properties can be ignored (default false)


**AVAILABLE QBS ITEMS**

These items designed as a shorthands implies corresponding features


**FKProduct** (not implemented yet)

This item implies to *helpers, content, imageset, mobile, deploy* features. Used to create ready-to-run deployed application structure not packed to installer.

Defined variables:
maintainer   (string, "")           - application maintainer (used by helpers feature to add maintainer define, see projectHelper.h for details)
deployFolder (path,   "../package") - application package target folder (used by content, imageset, deploy features as files copy destination root)


**FKInstaller** (not implemented yet)

This item implies to *deploy*. Used to create installer package from FKProduct.



**FULL LIST OF VARIABLES AND FILE TAGS REQUIRED TO USE FKFRAMEWORK 3 FEATURES**


|Variable/tag|Features|
|product.name|helpers|
|product.version|helpers|
|product.maintainer|helpers|
|product.deployFolder|content, imageset, deploy|
|"fk.content"|content|
|"fk.resource"|content|
|"fk.imageset"|imageset|
