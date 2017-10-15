import qbs
import "../DeployPackage.qbs" as DeployPackage


Project{

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


