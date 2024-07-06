#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CITIES 5       // 城市数目
#define POP_SIZE 100       // 种群大小
#define CROSS_RATE 0.8     // 交叉率
#define MUTATION_RATE 0.02 // 变异率
#define N_GENERATIONS 1000 // 迭代次数

int dist_matrix[NUM_CITIES][NUM_CITIES];

// 初始化距离矩阵
void init_distances() {
    int sample_matrix[NUM_CITIES][NUM_CITIES] = {
        {0, 29, 20, 21, 16},
        {29, 0, 15, 17, 28},
        {20, 15, 0, 18, 23},
        {21, 17, 18, 0, 12},
        {16, 28, 23, 12, 0}
    };

    for (int i = 0; i < NUM_CITIES; i++) {
        for (int j = 0; j < NUM_CITIES; j++) {
            dist_matrix[i][j] = sample_matrix[i][j];
        }
    }
}


// 打印距离矩阵
void print_distances() {
    printf("距离矩阵:\n");
    for (int i = 0; i < NUM_CITIES; i++) {
        for (int j = 0; j < NUM_CITIES; j++) {
            printf("%3d ", dist_matrix[i][j]);
        }
        printf("\n");
    }
}

// 初始化种群
void initial_population(int population[POP_SIZE][NUM_CITIES]) {
    for (int i = 0; i < POP_SIZE; i++) {
        for (int j = 0; j < NUM_CITIES; j++) {
            population[i][j] = j;
        }
        // 随机打乱顺序
        for (int j = 0; j < NUM_CITIES; j++) {
            int k = rand() % NUM_CITIES;
            int temp = population[i][j];
            population[i][j] = population[i][k];
            population[i][k] = temp;
        }
    }
}

// 计算适应度函数
double fitness(int individual[NUM_CITIES]) {
    int distance = 0;
    for (int i = 0; i < NUM_CITIES - 1; i++) {
        distance += dist_matrix[individual[i]][individual[i + 1]];
    }
    distance += dist_matrix[individual[NUM_CITIES - 1]][individual[0]];
    return 1.0 / distance;
}

// 选择操作
int* select(int population[POP_SIZE][NUM_CITIES], double fitnesses[POP_SIZE]) {
    double total_fitness = 0;
    for (int i = 0; i < POP_SIZE; i++) {
        total_fitness += fitnesses[i];
    }
    double rand_value = ((double) rand() / RAND_MAX) * total_fitness;
    double cumulative_fitness = 0;
    for (int i = 0; i < POP_SIZE; i++) {
        cumulative_fitness += fitnesses[i];
        if (cumulative_fitness >= rand_value) {
            return population[i];
        }
    }
    return population[POP_SIZE - 1];
}

// 交叉操作
void crossover(int parent1[NUM_CITIES], int parent2[NUM_CITIES], int child1[NUM_CITIES], int child2[NUM_CITIES]) {
    if (((double) rand() / RAND_MAX) < CROSS_RATE) {
        int start = rand() % NUM_CITIES;
        int end = rand() % NUM_CITIES;
        if (start > end) {
            int temp = start;
            start = end;
            end = temp;
        }

        int temp_child1[NUM_CITIES];
        int temp_child2[NUM_CITIES];
        for (int i = 0; i < NUM_CITIES; i++) {
            temp_child1[i] = -1;
            temp_child2[i] = -1;
        }

        for (int i = start; i <= end; i++) {
            temp_child1[i] = parent1[i];
            temp_child2[i] = parent2[i];
        }

        int k1 = (end + 1) % NUM_CITIES;
        int k2 = (end + 1) % NUM_CITIES;
        for (int i = 0; i < NUM_CITIES; i++) {
            int gene1 = parent2[(end + 1 + i) % NUM_CITIES];
            int gene2 = parent1[(end + 1 + i) % NUM_CITIES];

            int found1 = 0;
            int found2 = 0;
            for (int j = start; j <= end; j++) {
                if (temp_child1[j] == gene1) found1 = 1;
                if (temp_child2[j] == gene2) found2 = 1;
            }
            if (!found1) {
                temp_child1[k1] = gene1;
                k1 = (k1 + 1) % NUM_CITIES;
            }
            if (!found2) {
                temp_child2[k2] = gene2;
                k2 = (k2 + 1) % NUM_CITIES;
            }
        }

        for (int i = 0; i < NUM_CITIES; i++) {
            child1[i] = temp_child1[i];
            child2[i] = temp_child2[i];
        }
    } else {
        for (int i = 0; i < NUM_CITIES; i++) {
            child1[i] = parent1[i];
            child2[i] = parent2[i];
        }
    }
}

// 变异操作
void mutate(int individual[NUM_CITIES]) {
    if (((double) rand() / RAND_MAX) < MUTATION_RATE) {
        int i = rand() % NUM_CITIES;
        int j = rand() % NUM_CITIES;
        int temp = individual[i];
        individual[i] = individual[j];
        individual[j] = temp;
    }
}

int main() {
    init_distances();
    print_distances();

    int population[POP_SIZE][NUM_CITIES];
    initial_population(population);

    double fitnesses[POP_SIZE];
    for (int generation = 0; generation < N_GENERATIONS; generation++) {
        for (int i = 0; i < POP_SIZE; i++) {
            fitnesses[i] = fitness(population[i]);
        }

        int new_population[POP_SIZE][NUM_CITIES];
        for (int i = 0; i < POP_SIZE; i += 2) {
            int* parent1 = select(population, fitnesses);
            int* parent2 = select(population, fitnesses);
            int child1[NUM_CITIES];
            int child2[NUM_CITIES];
            crossover(parent1, parent2, child1, child2);
            mutate(child1);
            mutate(child2);
            for (int j = 0; j < NUM_CITIES; j++) {
                new_population[i][j] = child1[j];
                new_population[i + 1][j] = child2[j];
            }
        }

        for (int i = 0; i < POP_SIZE; i++) {
            for (int j = 0; j < NUM_CITIES; j++) {
                population[i][j] = new_population[i][j];
            }
        }
    }

    double best_fitness = -1.0;
    int best_individual[NUM_CITIES];
    for (int i = 0; i < POP_SIZE; i++) {
        double f = fitness(population[i]);
        if (f > best_fitness) {
            best_fitness = f;
            for (int j = 0; j < NUM_CITIES; j++) {
                best_individual[j] = population[i][j];
            }
        }
    }

    printf("最佳路径: ");
    for (int i = 0; i < NUM_CITIES; i++) {
        printf("%d ", best_individual[i]);
    }
    printf("\n最佳距离: %.2f\n", 1.0 / best_fitness);

    return 0;
}
