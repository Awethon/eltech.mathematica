#include "stdafx.h"
#include "Natural.h"

Natural::Natural() {
	vsize = 0;
}

Natural::Natural(string strnum) {
	vsize = strnum.length();
	natural_v.resize(vsize);
	for (unsigned int i = 0; i < vsize; i++) {
		natural_v.at(vsize - 1 - i) = strnum[i] - 48;
	}
}

unsigned short Natural::getDigit(unsigned int rank) {
	if (rank >= 0 && rank < vsize) {
		return natural_v[rank];
	}
	exit(-1);
};

unsigned int Natural::getSize() {
	return vsize;
};

void Natural::resize(unsigned int newSize) {
	natural_v.resize(newSize);
	vsize = newSize;
}

int Natural::COM_NN_D(Natural a, Natural b) {
	if (a.vsize > b.vsize)
		return 2;
	if (a.vsize < b.vsize)
		return 1;
	for (int i = a.vsize - 1; i >= 0; i--) {
		if (a.natural_v[i] > b.natural_v[i])
			return 2;
		if (a.natural_v[i] < b.natural_v[i])
			return 1;
	}
	return 0;
}

bool Natural::NZER_N_B(Natural a) {
	return (a.vsize == 1 && a.natural_v[0] == 0) ? false : true;
};

Natural Natural::ADD_1N_N(Natural a) {
	int i;
	for (i = 0; (i < a.vsize) ? (a.natural_v[i] == 9 ? true : false) : false; i++);

	if (i == a.vsize)
		a.resize(a.vsize + 1);
	for (int j = 0; j < i; j++)
		a.natural_v[j] = 0;
	a.natural_v[i]++;
	return a;
};

Natural Natural::ADD_NN_N(Natural a, Natural b) {
	Natural c;
	unsigned int i = 0;
	int r = 0;

	if (COM_NN_D(a, b) == 1)
		swap(a, b);
	c.resize(a.vsize);
	for (i = 0; i < b.vsize; i++) {
		c.natural_v[i] = (a.natural_v[i] + b.natural_v[i] + r) % 10;
		r = (a.natural_v[i] + b.natural_v[i] + r) / 10;
	}

	for (i; i < a.vsize; i++) {
		c.natural_v[i] = (a.natural_v[i] + r) % 10;
		r = (a.natural_v[i] + r) / 10;
	}
	if (r) {
		c.resize(c.getSize() + 1);
		c.natural_v[i] = r;
		i++;
	}
	return c;
};

Natural Natural::SUB_NN_N(Natural a, Natural b) {
	Natural c;
	int i = 0;
	int r = 0;

	if (COM_NN_D(a, b) == 1)
		swap(a, b);
	c.resize(a.getSize());

	for (i; i < b.getSize(); i++) {
		c.natural_v[i] = (a.natural_v[i] - b.natural_v[i] - r + 10) % 10;
		r = (a.natural_v[i] - b.natural_v[i] - r) >= 0 ? 0 : 1;
	}
	for (i; i < a.getSize(); i++) {
		c.natural_v[i] = (a.natural_v[i] - r + 10) % 10;
		r = (a.natural_v[i] - r) >= 0 ? 0 : 1;
	}
	while ((i > 0) ? (!c.natural_v[i - 1]) : false) {
		i--;
	}
	if (!i) i++;
	c.resize(i);
	return c;
};

Natural Natural::MUL_ND_N(Natural a, int D) {
	Natural c;
	int r = 0;

	c.resize(a.getSize());
	for (int j = 0; j < a.vsize; j++) {
		c.natural_v[j] = (a.natural_v[j] * D + r) % 10;
		r = (a.natural_v[j] * D + r) / 10;
	}
	if (r) {
		c.vsize++;
		c.resize(c.getSize());
		c.natural_v[c.vsize - 1] = r;
	}

	return c;
};

Natural Natural::MUL_Nk_N(Natural a, int k) {
	Natural c;
	int r = 0;
	c.resize(a.getSize() + k);
	for (int i = a.vsize - 1; i >= 0; i--)
		c.natural_v[i + k] = a.natural_v[i];
	for (int i = 0; i < k; i++)
		c.natural_v[i] = 0;
	return c;
};

Natural Natural::MUL_NN_N(Natural a, Natural b) {
	Natural c;
	for (unsigned i = 0; i < b.vsize; i++) {
		c = ADD_NN_N(c, MUL_Nk_N(MUL_ND_N(a, b.natural_v[i]), i));
	}
	return c;
};

Natural Natural::SUB_NDN_N(Natural a, int n, Natural b) {
	return (SUB_NN_N(a, MUL_ND_N(b, n)));
};

Natural Natural::DIV_NN_Dk(Natural a, Natural b) {
	Natural x = b;
	int j = a.vsize - b.vsize - 1;
	if (COM_NN_D(a, MUL_Nk_N(x, j + 1)) != 1)
		j++;
	x = MUL_Nk_N(x, j);
	int i = 1;
	while (COM_NN_D(MUL_ND_N(x, i + 1), a) == 1)
		i++;
	Natural res;
	res.resize(1);
	res.natural_v[0] = i;
	return MUL_Nk_N(res, j);
};

Natural Natural::DIV_NN_N(Natural a, Natural b) {
	Natural res("0");
	Natural sub;
	Natural c = a;
	while (COM_NN_D(c, b) != 1) {
		res = ADD_NN_N(res, DIV_NN_Dk(c, b));
		sub = MUL_NN_N(DIV_NN_Dk(c, b), b);
		c = SUB_NN_N(c, sub);
	}
	return res;
};

Natural Natural::MOD_NN_N(Natural a, Natural b) {
	return SUB_NN_N(a, MUL_NN_N(b, DIV_NN_N(a, b)));
};

Natural Natural::GCF_NN_N(Natural a, Natural b) {
	if (!NZER_N_B(a))
		return b;
	if (!NZER_N_B(b))
		return a;
	Natural x = a, y = b;
	if (COM_NN_D(x, y) == 1)
		swap(x, y);
	while (true) {
		Natural r = MOD_NN_N(x, y);
		if (!NZER_N_B(r))
			return y;
		x = y;
		y = r;
	}
};

Natural Natural::LCM_NN_N(Natural a, Natural b) {
	return DIV_NN_N(MUL_NN_N(a, b), GCF_NN_N(a, b));
};
