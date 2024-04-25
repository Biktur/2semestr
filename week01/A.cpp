#include<iostream>

int64_t** maximal_harvest(int64_t** field, size_t M, size_t N) {
    int64_t** harvest = new int64_t*[M];
    for (size_t i = 0; i < M; ++i) {
        harvest[i] = new int64_t[N];
        for (size_t j = 0; j < N; ++j) {
            if ((i == 0) and (j == 0)) {
                harvest[i][j] = field[i][j];
                continue;
            }
            if (i == 0) {
                harvest[i][j] = field[i][j] + harvest[i][j - 1];
                continue;
            }
            if (j == 0) {
                harvest[i][j] = field[i][j] + harvest[i - 1][j];
                continue;
            }
            if (harvest[i - 1][j] <= harvest[i][j - 1]) {
                harvest[i][j] = field[i][j] + harvest[i][j - 1];
                continue;
            }
            harvest[i][j] = field[i][j] + harvest[i - 1][j];
            continue;
        }
    }
    return harvest;
}

int64_t* path(int64_t** harvest, size_t M, size_t N) {
    int64_t* path = new int64_t[M];
    size_t coord[] = {M - 1, N - 1};
    size_t row = M - 1;
    for (size_t i = 0; i < M; ++i) {
        path[i] = 0;
    }
    for (size_t i = 0; i < N + M - 1; ++i) {
        if (coord[0] == 0) {
            ++path[row];
            --coord[1]; 
            continue;
        }
        if (coord[1] == 0) {
            ++path[row];
            --row;
            --coord[0];
            continue;
        }
        if (harvest[coord[0] - 1][coord[1]] <= harvest[coord[0]][coord[1] - 1]) {
            ++path[row];
            --coord[1]; 
            continue;
        }
        ++path[row];
        --row;
        --coord[0];
    }
    return path;
}

void merge(int64_t** &field, int64_t* path, size_t M, size_t N) {
    size_t current  = 0;
    for (size_t i = 0; i < M; ++i) {
        for (size_t j = 0; j < current; ++j) {
            field[i - 1][j] = field[i][j];
        }
        for (size_t j = current + path[i]; j < N; ++j) {
            field[i][j - 1] = field[i][j];
        }
        current += path[i] - 1;
    }
}

void print(int64_t** mat, size_t M, size_t N) {
    for (size_t i = 0; i < M; ++i) {
        for (size_t j = 0; j < N; ++j) {
            std::cout << mat[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void destroy_matrix(int64_t** &mat, size_t M, size_t N) {
    for (size_t i = 0; i < M; ++i) {
        delete[] mat[i];
    }
    delete[] mat;
}

int main() {
    size_t N = 0;
    size_t M = 0;
    std::cin >> N >> M;
    int64_t** field = new int64_t*[M];
    for (size_t i = 0; i < M; ++i) {
        field[i] = new int64_t[N];
        for (size_t j = 0; j < N; ++j) {
            std::cin >> field[i][j];
        }
    }
    size_t A = 0;
    std::cin >> A;
    int64_t sum = 0;
    size_t i = 0;
    for (i = 0; (i + 1 < A / (N + M - 2) + 1) and (i < M) and (i < N); ++i) {
        int64_t** harvest = maximal_harvest(field, M - i, N - i);
        sum += harvest[M - i - 1][N - i - 1];
        int64_t* pat = path(harvest, M - i, N - i);
        merge(field, pat, M - i, N - i);
        destroy_matrix(harvest, M - i, N - i);
        delete[] pat;
    }
    std::cout << sum;
    if ((i == M) or (i == N)) {
        std::cout << sum;
        destroy_matrix(field, M, N);
        return 0;
    }
    int64_t** harvest = maximal_harvest(field, M - i, N - i);
    int64_t max = 0;
    int64_t fuel = (A % (N + M - 2)) - i;
    for (size_t j = fuel * (fuel + i <= M - 1) * (fuel + i >= i) + (M - i - 1) * (fuel + i > M - 1) * (M - 1 >= i); (fuel - j) <= fuel * (fuel + i <= N - 1) * (fuel + i >= i) + (N - i - 1) * (fuel + i > N - 1) * (N - 1 >= i); --j) {
        if (max < harvest[j][fuel - j]) {
            max = harvest[j][fuel - j];
        }
    }
    print(harvest, M - i, N - i);
    std::cout << max + sum << std::endl;
    destroy_matrix(harvest, M - i, N - i);
    destroy_matrix(field, M, N);
}