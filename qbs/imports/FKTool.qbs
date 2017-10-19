import qbs

QtApplication{

    type: "deployedPackage"
    Depends{ name: "FK"; submodules: ["helpers", "deploy"] }

    Group{
        fileTagsFilter: "application"
        fileTags: "deployable"
        overrideTags: false
    }

    FK.deploy.root: utilsFolder
    FK.helpers.skipValidation: true
    FK.helpers.searchRoot: product.sourceDirectory
}
