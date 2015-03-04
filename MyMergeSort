void merge(string &a, int l, int m, int r)
{
	int i = l, j = m + 1, k = 0;
	string temp;
	while (i <= m && j <= r)
	{
		if (a[i] < a[j])
			temp += a[i++];
		else
			temp += a[j++];
	}
	while (i <= m)
		temp += a[i++];
	while (j <= r)
		temp += a[j++];
	for (int i = 0; i < r - l + 1; i++)
		a[l + i] = temp[i];
}

void mergeSort(string &a, int l, int r)
{
	if (l >= r) return;
	int m = l - (l - r) / 2;
	mergeSort(a, l, m);
	mergeSort(a, m + 1, r);
	merge(a, l, m, r);
}
