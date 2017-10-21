import qbs
import "../features/qbs/scripts/fkframeworkpath.js" as FKPaths

Project{

    property path utilsFolder: FKPaths.frameworkPath(qbs.hostOS) + "/utils"

    FKTool{
        name: "ImageManager"
        Depends{ name: "Qt"; submodules: ["gui", "qml", "quick"] }
        files: [
            "ImageManager/main.cpp",
            "ImageManager/ImageChecker.cpp",
            "ImageManager/ImageChecker.h",
            "ImageManager/qml.qrc",
            "ImageManager/deployTemplates.qrc"
        ]
    }

    FKTool{
        name: "PackageManager"
        consoleApplication: true
        files: [
            "PackageManager/main.cpp",
            "PackageManager/PackageManager.cpp",
            "PackageManager/PackageManager.h"
        ]
    }

    FKTool{
        name: "PackageGenerator"
        consoleApplication: true
        Depends{ name: "Qt"; submodules: ["concurrent", "gui"] }
        files: [
            "PackageGenerator/main.cpp",
            "PackageGenerator/PackageGenerator.cpp",
            "PackageGenerator/PackageGenerator.h"
        ]
    }


    FKTool{
        name: "DeployQML"
        consoleApplication: true
        files: [
            "DeployQML/main.cpp"
        ]
    }

    DeployPackage{
        name: "deployDesktop"
        Group{
            files: [
                "deployDesktop/fkdeploy.pri",
                "deployDesktop/buildConfig.txt",
                "deployDesktop/Install.wxs",
                "deployDesktop/nixDeploy.sh",
                "deployDesktop/nixdeployqt.sh",
                "deployDesktop/nixRun.sh",
                "deployDesktop/target.desktop",
                "deployDesktop/winDeploy.bat",
                "deployDesktop/DEBIAN/*"
            ]
            fileTags: ["fk.deployable"]
        }
    }

    DeployPackage{
        name: "deployMobile"
        Group{
            files: [
                "deployMobile/fkdeploy_mobile.pri",
                "deployMobile/Info.plist",
                "deployMobile/android_splashScreen/**",
                "deployMobile/ios_splashScreen/*"
            ]
            fileTags: ["fk.deployable"]
        }
    }

    DeployPackage{
        name: "contentPacker"
        Group{
            files: [
                "contentPacker/fkimageset.pri",
                "contentPacker/fkcontent.pri"
            ]
            fileTags: ["fk.deployable"]
        }
    }

    DeployPackage{
        name: "helpers"
        Group{
            files: [
                "helpers/fkhelpers.pri",
                "helpers/*.h"
            ]
            fileTags: ["fk.deployable"]
        }
    }

}


