import qbs
import "../../../scripts/fkframeworkpath.js" as FKPaths

Module{

    property bool skipValidation: false
    property path searchRoot: FKPaths.frameworkPath(qbs.hostOS) + "/utils"

    Depends{ name: "cpp" }
    cpp.includePaths: searchRoot + "/helpers"
    cpp.defines: [
        'APP_VERSION="' + product.version + '"',
        'APP_NAME="' + product.name + '"',
        'APP_MAINTAINER="' + product.maintainer + '"'
    ]

    validate: {
        if(skipValidation)
            return

        if(product.version === undefined)
            throw "Set product version or set FK.helpers.skipValidation to true"

        if(product.name === undefined)
            throw "Set product name or set FK.helpers.skipValidation to true"

        if(product.maintainer === undefined)
            throw "Create property and set product maintainer or set FK.helpers.skipValidation to true"
    }

}
