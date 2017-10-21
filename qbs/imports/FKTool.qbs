import qbs

QtApplication{
    Depends{ name: "FK"; submodules: ["helpers", "deploy"] }
    property path deployFolder: project.utilsFolder
    FK.helpers.skipValidation: true
    FK.helpers.searchRoot: product.sourceDirectory
}
