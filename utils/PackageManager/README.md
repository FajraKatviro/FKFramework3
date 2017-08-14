# Imageset system

Imagesets are designed to provide good-looking solution depending on device screen resolution.
2D images can be packed to special packages called imagesets.
You should create each imageset in a separate folder.
First, you should add target resolution and add basic images to package.
Then, you can add more resolutions and add custom image for each resolution, assign existed one or use the default one.
Default means 'nearest size'.
When you build imageset, you will get 1 package with multiple resource: one for each defined resolution.
Then you should load resource via resource locator using FKUtils::selectBestSize() function
Best size means 'nearest size' as well (nearest to device resolution).
When calculationg nearest size, larger sizes are preferrable, but limited (if too much downscale required, it will use smaller sizes).
Size-match multiplier calculated when resource is loaded. If device screen resolution is equal to loaded imageset, then size-match multiplier == 1.
The same size-match multiplier applied to all images from the imageset.

If you need non-scalable images, use 'content' feature instead.



**Imageset system uses 3 tools:**

**PackageManager**

Package manager is the main tool used to define imagesets.
It creates and manages json files describing imagesets.

**ImageManager**

Image manager is the GUI tool for designing imagesets.
It allow create imagesets, add/remove sizepacks, manage used images.
Also this tool allows create icons and splashscreens for deployMobile feature.

*PackageGenerator**

Package generator is the tool used to create content packages from imageset json description.
Internally it uses Qt resource compiler to create binary resource files.
The tool have different invoke options. See internal app manual for details.