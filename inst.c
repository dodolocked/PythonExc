#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // 指定要运行的Python脚本路径
    char *script_path = "main.py";  // 请替换为你的脚本路径

    // 计算命令长度
    int cmd_len = strlen("python ") + strlen(script_path) + 1;
    for (int i = 1; i < argc; i++) {
        cmd_len += strlen(argv[i]) + 1;
    }

    // 分配命令字符串
    char *cmd = (char *)malloc(cmd_len * sizeof(char));
    if (cmd == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // 构建命令字符串
    strcpy(cmd, "python ");
    strcat(cmd, script_path);
    for (int i = 1; i < argc; i++) {
        strcat(cmd, " ");
        strcat(cmd, argv[i]);
    }

    // 打印命令（调试用）
    // printf("Command: %s\n", cmd);

    // 运行命令
    int ret = system(cmd);

    // 释放内存
    free(cmd);

    return ret;
}
