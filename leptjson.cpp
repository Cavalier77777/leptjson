#include <cassert>
#include <string>
#include "leptjson.h"

namespace lept {
	#define EXPECT(c,ch) do {assert(*c.json == (ch));c.json++;}while(0)

	typedef struct {
		const char* json;
	} lept_context;


	static void lept_parse_whitespace(lept_context& c){
		auto p = c.json;
		while(*p == ' ' || *p == '\n' || *p == '\t' || *p == '\r')
			p++;
		c.json = p;
	}

	static int lept_parse_null(lept_context& c,lept_value& v) {
		EXPECT(c,'n');
		if(c.json[0] != 'u' || c.json[1] != 'l' || c.json[2] != 'l') {
			return LEPT_PARSE_INVALID_VALUE;
		}
		c.json += 3;
		v.type = LEPT_NULL;

		return LEPT_PARSE_OK;
	}

	static int lept_parse_value(lept_context& c,lept_value& v) {
		switch(*c.json) {
			case 'n':
				return lept_parse_null(c,v);
			case '\0':
				return LEPT_PARSE_EXCEPT_VALUE;
			default:
				return LEPT_PARSE_INVALID_VALUE;
		}
	}

	int lept_parse(lept_value& v,const char* json) {
		lept_context c;
		c.json = json;
		v.type = LEPT_NULL;

		lept_parse_whitespace(c);
		return lept_parse_value(c,v);
	}

	lept_type lept_get_value(const lept_value& v) {
		return v.type;
	}
				
}
