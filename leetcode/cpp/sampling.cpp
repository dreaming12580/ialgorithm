


private int[] sampling(int K) {
	int[] result = new int[K];
	for (int i = 0; i < K; ++i) {
		result[i] = pool[i];
	}
	for (int i = K; i < N; ++i) {
		int r = random.nextInt(i + 1);
		if (r < K) {
			result[r] = pool[i];
		}
	}
	return result;
}








