import Foundation

let file = "Grace_kid.swift"

let fd = open(file, O_WRONLY|O_CREAT, 0o666)
if fd > 0 {
    let str = "    let buff = \"import Foundation\\n\\nlet file = \\\"Grace_kid.swift\\\"\\n\\nlet fd = open(file, O_WRONLY|O_CREAT, 0o666)\\nif fd > 0 {\\n    let str = \\(str.debugDescription)\\n\\(str)\"\n    write(fd, buff, strlen(buff))\n    close(fd)\n}\n"
    let buff = "import Foundation\n\nlet file = \"Grace_kid.swift\"\n\nlet fd = open(file, O_WRONLY|O_CREAT, 0o666)\nif fd > 0 {\n    let str = \(str.debugDescription)\n\(str)"
    write(fd, buff, strlen(buff))
    close(fd)
}
