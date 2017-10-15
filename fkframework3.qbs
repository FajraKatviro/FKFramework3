import qbs

Project{

    minimumQbsVersion: "1.9.1"

    name: "FKFramework 3"

    references: [
        "features/features.qbs"//,
        //"utils/utils.qbs"
    ]

    qbsSearchPaths: "."

    Product{
        name: "Other files"
        files: [
            "README.md",
            "LICENSE",
            "paths/README.md",
            "paths/fkframeworkpath.pri",
            "paths/fkframework.pri"
        ]
    }
}
