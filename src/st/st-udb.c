
unsigned udb_int (unsigned n, unsigned * keys)
{
  st_table * ht = st_init_numtable ();
  unsigned i;
  unsigned count;

  for (i = 0; i < n; i ++)
    {
      /* local variable key is needed by st_delete() (it requires a pointer) */
      st_data_t key = (st_data_t) keys [i];
      if (st_is_member (ht, key))
	st_delete (ht, & key, NULL);
      else
	st_insert (ht, key, i);
    }

  count = ht -> num_entries;

  st_free_table (ht);

  return count;
}


unsigned udb_str (unsigned n, char ** keys)
{
  st_table * ht = st_init_strtable ();
  unsigned i;
  unsigned count;

  for (i = 0; i < n; i ++)
    {
      /* local variable key is needed by st_delete() (it requires a pointer) */
      st_data_t key = (st_data_t) keys [i];
      if (st_is_member (ht, (st_data_t) keys [i]))
	st_delete (ht, & key, NULL);
      else
	st_insert (ht, (st_data_t) keys [i], i);
    }

  count = ht -> num_entries;

  st_free_table (ht);

  return count;
}
