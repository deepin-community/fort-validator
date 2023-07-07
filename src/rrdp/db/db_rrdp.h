#ifndef SRC_RRDP_DB_DB_RRDP_H_
#define SRC_RRDP_DB_DB_RRDP_H_

#include "rrdp/db/db_rrdp_uris.h"

int db_rrdp_init(void);
void db_rrdp_cleanup(void);

int db_rrdp_add_tal(char const *);
void db_rrdp_rem_tal(char const *);

struct db_rrdp_uri *db_rrdp_get_uris(char const *);
char const *db_rrdp_get_workspace(char const *);

void db_rrdp_reset_visited_tals(void);
void db_rrdp_rem_nonvisited_tals(void);

#endif /* SRC_RRDP_DB_DB_RRDP_H_ */
