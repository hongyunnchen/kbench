
unsigned udb_int (unsigned n, unsigned * keys)
{
  khash_t(uht_t) * ht = kh_init (uht_t);
  unsigned i;
  int ret;
  unsigned count;

  for (i = 0; i < n; i ++)
    {
      khiter_t hit = kh_get (uht_t, ht, keys [i]);
      if (hit != kh_end (ht))
	kh_del (uht_t, ht, hit);
      else
	{
	  kh_put (uht_t, ht, keys [i], & ret);
	  kh_value (ht, hit) = i + 1;
	}
    }

  count = kh_size (ht);

  kh_destroy (uht_t, ht);

  return count;
}


unsigned udb_str (unsigned n, char ** keys)
{
  khash_t(sht_t) * ht = kh_init (sht_t);
  unsigned i;
  int ret;
  unsigned count;

  for (i = 0; i < n; i ++)
    {
      khiter_t hit = kh_get (sht_t, ht, keys [i]);
      if (hit != kh_end (ht))
	kh_del (sht_t, ht, hit);
      else
	{
	  kh_put (sht_t, ht, keys [i], & ret);
	  kh_value (ht, hit) = i;
	}
    }

  count = kh_size (ht);

  kh_destroy (sht_t, ht);

  return count;
}
