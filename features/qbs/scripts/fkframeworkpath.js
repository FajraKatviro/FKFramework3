
var Environment = require("qbs.Environment")

function frameworkPath(hostOS){

    var path

    if (hostOS.contains("linux"))
        path = Environment.getEnv("HOME") + "/FKFramework"
    else if (hostOS.contains("macos"))
        path = Environment.getEnv("HOME") + "/Applications/FKFramework"
    else if (hostOS.contains("windows"))
        path = Environment.getEnv("APPDATA") + "/FKFramework"

    return path
}

