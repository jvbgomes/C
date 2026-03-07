#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MODS 3
static const int MOD[MODS] = {1000000007, 1000000009, 998244353};

typedef struct {
	long long w;
	long long *coord;
} Vector;

typedef struct {
	int mod;
	int d;
	int rank;
	int *pivot_col;
	int *basis; /* basis[row * d + col] */
} ModBasis;

static int cmp_desc_weight(const void *a, const void *b) {
	const Vector *va = (const Vector *)a;
	const Vector *vb = (const Vector *)b;

	if (va->w < vb->w) return 1;
	if (va->w > vb->w) return -1;
	return 0;
}

static int mod_norm(long long x, int mod) {
	long long r = x % mod;
	if (r < 0) r += mod;
	return (int)r;
}

static int mod_pow(int a, int e, int mod) {
	long long res = 1;
	long long base = a;
	while (e > 0) {
		if (e & 1) res = (res * base) % mod;
		base = (base * base) % mod;
		e >>= 1;
	}
	return (int)res;
}

static int mod_inv(int a, int mod) {
	/* mod is prime */
	return mod_pow(a, mod - 2, mod);
}

static int try_insert_vector(ModBasis *mb, const long long *coord, int do_insert, int *work) {
	int d = mb->d;
	int mod = mb->mod;

	for (int c = 0; c < d; c++) {
		work[c] = mod_norm(coord[c], mod);
	}

	for (int r = 0; r < mb->rank; r++) {
		int pc = mb->pivot_col[r];
		int factor = work[pc];
		if (factor == 0) continue;

		int *row = mb->basis + r * d;
		for (int c = pc; c < d; c++) {
			long long val = work[c] - (long long)factor * row[c] % mod;
			if (val < 0) val += mod;
			work[c] = (int)val;
		}
	}

	int new_pivot = -1;
	for (int c = 0; c < d; c++) {
		if (work[c] != 0) {
			new_pivot = c;
			break;
		}
	}

	if (new_pivot == -1) {
		return 0;
	}

	if (!do_insert) {
		return 1;
	}

	int inv = mod_inv(work[new_pivot], mod);
	for (int c = new_pivot; c < d; c++) {
		work[c] = (int)((long long)work[c] * inv % mod);
	}

	int pos = mb->rank;
	while (pos > 0 && mb->pivot_col[pos - 1] > new_pivot) {
		mb->pivot_col[pos] = mb->pivot_col[pos - 1];
		memcpy(mb->basis + pos * d, mb->basis + (pos - 1) * d, (size_t)d * sizeof(int));
		pos--;
	}

	mb->pivot_col[pos] = new_pivot;
	int *new_row = mb->basis + pos * d;
	for (int c = 0; c < d; c++) {
		new_row[c] = (c < new_pivot) ? 0 : work[c];
	}

	for (int r = 0; r < mb->rank; r++) {
		int *row = mb->basis + r * d;
		int factor = row[new_pivot];
		if (factor == 0) continue;

		for (int c = new_pivot; c < d; c++) {
			long long val = row[c] - (long long)factor * new_row[c] % mod;
			if (val < 0) val += mod;
			row[c] = (int)val;
		}
		row[new_pivot] = 0;
	}

	mb->rank++;
	return 1;
}

int main(void) {
	int d, n;
	if (scanf("%d %d", &d, &n) != 2) {
		return 0;
	}

	Vector *v = (Vector *)malloc((size_t)n * sizeof(Vector));
	if (v == NULL) {
		return 0;
	}

	for (int i = 0; i < n; i++) {
		v[i].coord = (long long *)malloc((size_t)d * sizeof(long long));
		if (v[i].coord == NULL) {
			for (int k = 0; k < i; k++) free(v[k].coord);
			free(v);
			return 0;
		}

		for (int j = 0; j < d; j++) {
			scanf("%lld", &v[i].coord[j]);
		}
		scanf("%lld", &v[i].w);
	}

	qsort(v, (size_t)n, sizeof(Vector), cmp_desc_weight);

	ModBasis mb[MODS];
	for (int k = 0; k < MODS; k++) {
		mb[k].mod = MOD[k];
		mb[k].d = d;
		mb[k].rank = 0;
		mb[k].pivot_col = (int *)malloc((size_t)d * sizeof(int));
		mb[k].basis = (int *)calloc((size_t)d * (size_t)d, sizeof(int));
		if (mb[k].pivot_col == NULL || mb[k].basis == NULL) {
			for (int kk = 0; kk <= k; kk++) {
				free(mb[kk].pivot_col);
				free(mb[kk].basis);
			}
			for (int i = 0; i < n; i++) free(v[i].coord);
			free(v);
			return 0;
		}
	}

	int *work[MODS];
	for (int k = 0; k < MODS; k++) {
		work[k] = (int *)malloc((size_t)d * sizeof(int));
		if (work[k] == NULL) {
			for (int kk = 0; kk < MODS; kk++) {
				free(work[kk]);
				free(mb[kk].pivot_col);
				free(mb[kk].basis);
			}
			for (int i = 0; i < n; i++) free(v[i].coord);
			free(v);
			return 0;
		}
	}

	long long ans = 0;
	int accepted = 0;

	for (int i = 0; i < n; i++) {
		if (v[i].w <= 0) break;
		if (accepted == d) break;

		int independent_all_mods = 1;
		for (int k = 0; k < MODS; k++) {
			if (!try_insert_vector(&mb[k], v[i].coord, 0, work[k])) {
				independent_all_mods = 0;
				break;
			}
		}

		if (!independent_all_mods) {
			continue;
		}

		for (int k = 0; k < MODS; k++) {
			(void)try_insert_vector(&mb[k], v[i].coord, 1, work[k]);
		}

		ans += v[i].w;
		accepted++;
	}

	printf("%lld\n", ans);

	for (int k = 0; k < MODS; k++) {
		free(work[k]);
		free(mb[k].pivot_col);
		free(mb[k].basis);
	}
	for (int i = 0; i < n; i++) {
		free(v[i].coord);
	}
	free(v);

	return 0;
}