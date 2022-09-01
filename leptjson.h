# ifndef LEPTJSON_H
# define LEPTJSON_H


namespace lept {

	typedef enum {
		LEPT_NULL,
		LEPT_FALSE,
		LEPT_TRUE,
		LEPT_NUMBER,
		LEPT_STRING,
		LEPT_ARRAY,
		LEPT_OBJECT
	} lept_type;

	typedef struct {
		lept_type type;
	}lept_value;
	
	enum {
		LEPT_PARSE_OK = 0,
		LEPT_PARSE_EXCEPT_VALUE, // only blank
		LEPT_PARSE_INVALID_VALUE, // There are other characters after the blank after a value
		LEPT_PARSE_ROOT_NOT_SINGULAR
	};

	int lept_parse(lept_value& v,const char* json);
	lept_type lept_get_type(const lept_value& v);
}
#endif
