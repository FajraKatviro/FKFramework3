import qbs
import "../DeployPackage.qbs" as DeployPackage

Project{

    DeployPackage{

        Group{
            files: "fkfeatures.pri"
            fileTags: ["deployable"]
        }

    }

}
