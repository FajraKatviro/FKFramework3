import qbs

Product{
    Depends{ name: "FK.fileDeploy" }
    property path deployFolder: utilsFolder
}
