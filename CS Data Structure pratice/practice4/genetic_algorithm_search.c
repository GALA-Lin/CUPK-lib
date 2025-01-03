#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define POP_SIZE 300  // 种群大小
#define GENERATIONS 3000  // 迭代次数
#define MUTATION_RATE 0.02  // 变异概率
#define CROSSOVER_RATE 0.7  // 交叉概率
#define PI 3.14159265358979323846

// 随机生成区间 [0, 1] 内的双精度浮点数
double rand_double() {
    return rand() / (double)RAND_MAX;
}

// 随机生成区间 [min, max] 内的双精度浮点数
double rand_range(double min, double max) {
    return min + (max - min) * rand_double();
}

// 适应度函数，目标是最大化该函数
double fitness(double x) {
    return sin(x) + cos(2 * x);
}

// 初始化种群
void initialize_population(double population[]) {
    for (int i = 0; i < POP_SIZE; ++i) {
        population[i] = rand_range(0, PI / 2);
    }
}

// 选择一个个体（使用轮盘赌选择）
double selection(double population[], double fitness_values[]) {
    double total_fitness = 0.0;
    for (int i = 0; i < POP_SIZE; ++i) {
        total_fitness += fitness_values[i];
    }

    double random_value = rand_double() * total_fitness;
    double cumulative_sum = 0.0;
    for (int i = 0; i < POP_SIZE; ++i) {
        cumulative_sum += fitness_values[i];
        if (cumulative_sum >= random_value) {
            return population[i];
        }
    }

    return population[POP_SIZE - 1];  // 返回最后一个个体（保险起见）
}

// 交叉操作
void crossover(double parent1, double parent2, double *child1, double *child2) {
    if (rand_double() < CROSSOVER_RATE) {
        double alpha = rand_double();
        *child1 = alpha * parent1 + (1 - alpha) * parent2;
        *child2 = alpha * parent2 + (1 - alpha) * parent1;
    } else {
        *child1 = parent1;
        *child2 = parent2;
    }
}

// 变异操作
void mutate(double *individual) {
    if (rand_double() < MUTATION_RATE) {
        *individual = rand_range(0, PI / 2);
    }
}

int main() {
    srand(time(NULL));

    double population[POP_SIZE];
    double new_population[POP_SIZE];
    double fitness_values[POP_SIZE];

    // 初始化种群
    initialize_population(population);

    // 进化过程
    for (int generation = 0; generation < GENERATIONS; ++generation) {

        // 评估适应度
        for (int i = 0; i < POP_SIZE; ++i) {
            fitness_values[i] = fitness(population[i]);
        }

        // 生成新的种群
        for (int i = 0; i < POP_SIZE; i += 2) {
            double parent1 = selection(population, fitness_values);
            double parent2 = selection(population, fitness_values);

            double child1, child2;
            crossover(parent1, parent2, &child1, &child2);
            mutate(&child1);
            mutate(&child2);

            new_population[i] = child1;
            new_population[i + 1] = child2;
        }

        // 替换旧种群
        for (int i = 0; i < POP_SIZE; ++i) {
            population[i] = new_population[i];
        }
    }

    // 找到最优解
    double best_individual = population[0];
    double best_fitness = fitness(best_individual);
    for (int i = 1; i < POP_SIZE; ++i) {
        double current_fitness = fitness(population[i]);
        if (current_fitness > best_fitness) {
            best_fitness = current_fitness;
            best_individual = population[i];
        }
    }

    // 最大值
    printf("Maximum value found at x = %f, f(x) = %f\n", best_individual, best_fitness);

    // 找到最优解
    double worst_individual = population[0];
    double worst_fitness = fitness(worst_individual);
    for (int i = 1; i < POP_SIZE; ++i) {
        double current_fitness = fitness(population[i]);
        if (current_fitness < worst_fitness) {
            worst_fitness = current_fitness;
            worst_individual = population[i];
        }
    }

    // 最小值
    printf("Minimum value found at x = %f, f(x) = %f\n", worst_individual, worst_fitness);

    return 0;
}
