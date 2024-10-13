int numberOfTheWinner(int N, int k) {
    int winner = 0; 
    for (int i = 2; i <= N; ++i)
        winner = (winner + k) % i; 
    return winner + 1;
}