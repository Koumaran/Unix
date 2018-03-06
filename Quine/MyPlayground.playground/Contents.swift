//: Playground - noun: a place where people can play

import Foundation

let file = "Grace_kid.swift"

var fd = open(file, O_CREAT|O_WRONLY)
if fd > 0 {
    let str = "    let buff = \"import Foundation\\n\\nlet file = \\"Grace_kid.swift\\"\\n\\nvar fd = open(file, O_CREAT|O_WRONLY)\\nif fd > 0 {\\n    let str = \\(str.debugDescription)\\n\\(str)\"\n    write(fd, buff, strlen(buff))\n    close(fd)\n}\n"
    let buff = "import Foundation\n\nlet file = \"Grace_kid.swift\"\n\nvar fd = open(file, O_CREAT|O_WRONLY)\nif fd > 0 {\n    let str = \(str.debugDescription)\n\(str)"
    write(fd, buff, strlen(buff))
    close(fd)
}

