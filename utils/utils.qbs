import qbs
import "../DeployPackage.qbs" as DeployPackage


Project{

    QtGuiApplication{
        name: "ImageManager"
        type: "deployedApp"
        Depends{ name: "deploy" }
        Depends{ name: "Qt"; submodules: ["qml", "quick"] }
        cpp.includePaths: "helpers"
        deploy.root: "utils"
        files: [
            "ImageManager/main.cpp",
            "ImageManager/ImageChecker.cpp",
            "ImageManager/ImageChecker.h",
            "ImageManager/qml.qrc",
            "ImageManager/deployTemplates.qrc"
        ]
    }

    QtApplication{
        name: "PackageManager"
        consoleApplication: true
        type: "deployedApp"
        Depends{ name: "deploy" }
        cpp.includePaths: "helpers"
        deploy.root: "utils"
        files: [
            "PackageManager/main.cpp",
            "PackageManager/PackageManager.cpp",
            "PackageManager/PackageManager.h"
        ]
    }

    QtApplication{
        name: "PackageGenerator"
        consoleApplication: true
        type: "deployedApp"
        Depends{ name: "deploy" }
        Depends{ name: "Qt"; submodules: ["concurrent", "gui"] }
        cpp.includePaths: "helpers"
        deploy.root: "utils"
        files: [
            "PackageGenerator/main.cpp",
            "PackageGenerator/PackageGenerator.cpp",
            "PackageGenerator/PackageGenerator.h"
        ]
    }

    QtApplication{
        name: "DeployQML"
        consoleApplication: true
        type: "deployedApp"
        Depends{ name: "deploy" }
        cpp.includePaths: "helpers"
        deploy.root: "utils"
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
            fileTags: ["deployable"]
            deploy.root: "utils"
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
            fileTags: ["deployable"]
            deploy.root: "utils"
        }
    }

    DeployPackage{
        name: "contentPacker"
        Group{
            files: [
                "contentPacker/fkimageset.pri",
                "contentPacker/fkcontent.pri"
            ]
            fileTags: ["deployable"]
            deploy.root: "utils"
        }
    }

    DeployPackage{
        name: "helpers"
        Group{
            files: [
                "helpers/fkhelpers.pri",
                "helpers/*.h"
            ]
            fileTags: ["deployable"]
            deploy.root: "utils"
        }
    }

}


