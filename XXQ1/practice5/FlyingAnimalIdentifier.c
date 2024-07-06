#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// 定义规则结构体
typedef struct {
    char *condition;
    char *result;
} Rule;

// 定义规则库
Rule rules[] = {
    {"会飞", "是飞行动物"},
     {"是鸟类", "是飞行动物"},
     {"是蝙蝠", "是飞行动物"},
     {"不会飞", "不是飞行动物"},
     {"不是鸟类", "不是飞行动物"},
     {"不是蝙蝠", "不是飞行动物"},
    {NULL, NULL} // 规则库结束标志
};

// 定义当前状态
char *current_state = "不会飞";

//打印规则库
void print_rules() {
    for (int i = 0; rules[i].condition != NULL; i++) {
        printf("%s -> %s\n", rules[i].condition, rules[i].result);
    }
}

// 匹配函数
bool match(char *condition) {
    return (condition != NULL && current_state != NULL && strcmp(condition, current_state) == 0);
}

// 选择函数
Rule *select_rule() {
    for (int i = 0; rules[i].condition != NULL; i++) {
        if (match(rules[i].condition)) {
            return &rules[i];
        }
    }
    return NULL;
}

// 应用函数
void apply_rule(Rule *rule) {
    if (rule != NULL) {
        current_state = rule->result;
        printf("应用规则: %s -> %s\n", rule->condition, rule->result);
    }
}

int main() {
    // 打印规则库
    printf("规则库:\n");
    print_rules();

    // 打印初始状态
    printf("初始状态: %s\n", current_state);

    // 反复推演
    while (true) {
        Rule *selected_rule = select_rule();
        if (selected_rule == NULL) {
            printf("没有匹配的规则，推理结束。\n");
            break;
        }
        apply_rule(selected_rule);
        if (strcmp(current_state, "是飞行动物") == 0 || strcmp(current_state, "是鸟类") == 0 || strcmp(current_state, "是蝙蝠") == 0) {
            printf("识别结果: %s\n", current_state);
            break;
        }
    }

    return 0;
}
