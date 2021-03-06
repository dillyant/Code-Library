#ifndef J_AC_BM_H
#define J_AC_BM_H
#define PATTERN_LEN	1024
#define NMAX_LEN   	32

typedef struct _pattern_tree_node {
	int label;
	int depth;
	
	unsigned char ch;
	int case_sen;
	int GSshift;		// Good Suffix shift for this char

	unsigned char one_child;
	struct _pattern_tree_node *childs[256];
	int nchild;
	struct _pattern_tree_node *parent;
} pattern_tree_node;

/* */
typedef struct _pattern_data {
	int len;
	int case_sen;
	unsigned char data[PATTERN_LEN];
} pattern_data;

typedef struct _pattern_tree {
	pattern_tree_node *root; // root of tree
	int max_depth;
	int min_pattern_size;
	int BCshift[256];	// Bad Char shift for 256 chars
	pattern_data *pattern_list; 	// pointed to structure arrays
	int pattern_count;
} pattern_tree;

typedef struct _matched_info {
	int pattern_i;
	unsigned long offset; 
} matched_info_t;

pattern_tree *acbm_init(pattern_data *patterns, int npattern);
int acbm_search(pattern_tree *ptree, unsigned char *text, int text_len, unsigned int matched_indexs[], int nmax_index);
inline int acbm_search_ex(pattern_tree *ptree, unsigned char *text, int text_len, \
		matched_info_t matched_items[], int nmax_index);
void acbm_clean(pattern_tree *ptree);
/*added by wyang*/
pattern_tree *acbmback_init(pattern_data *patterns, int npattern);

#endif
