#ifndef _QGEN_GAME_H_
	#define _QGEN_GAME_H_

	#include "datacontainer.h"

	#ifdef _UNICODE
		typedef wchar_t QGEN_CHAR;
		#define QGEN_FMT2(x) L##x
		#define QGEN_FMT(x) QGEN_FMT2(x)
	#else
		typedef char QGEN_CHAR;
		#define QGEN_FMT(x) x
	#endif

	#ifdef _UNICODE
		#define QGEN_STRCPY wcscpy
		#define QGEN_STRNCPY wcsncpy
		#define QGEN_STRLEN wcslen
		#define QGEN_STRSTR wcsstr
		#define QGEN_STRCHR wcschr
		#define QGEN_STRTOL wcstol
		#define QGEN_CHRLWR towlower
		#define QGEN_CHRUPR towupper
		#define QGEN_STRCMP wcscmp
		#define QGEN_STRCOLL wcscmp
		#define QGEN_STRPBRK wcspbrk
		#define QGEN_ISDIGIT iswdigit
		#define QGEN_WCSTOMBSLEN(a) wcstombs(0, a, 0)
		#define QGEN_WCSTOMBS wcstombs
		#define QGEN_MBTOSB(a) ((a) % 256)
		#define QGEN_FROM_OS_CHAR(a) qspReverseConvertUC(a, qspCP1251ToUnicodeTable)
		#define QGEN_TO_OS_CHAR(a) qspDirectConvertUC(a, qspCP1251ToUnicodeTable)
		#define QGEN_WCTOB
		#define QGEN_BTOWC
	#else
		#define QGEN_STRCPY strcpy
		#define QGEN_STRNCPY strncpy
		#define QGEN_STRLEN strlen
		#define QGEN_STRSTR strstr
		#define QGEN_STRCHR strchr
		#define QGEN_STRTOL strtol
		#define QGEN_STRCMP strcmp
		#define QGEN_STRPBRK strpbrk
		#define QGEN_ISDIGIT isdigit
		#define QGEN_WCSTOMBSLEN strlen
		#define QGEN_WCSTOMBS strncpy
		#define QGEN_MBTOSB
		#ifdef _WINDOWS
			#define QGEN_FROM_OS_CHAR
			#define QGEN_TO_OS_CHAR
			#define QGEN_WCTOB(a) qspReverseConvertUC(a, qspCP1251ToUnicodeTable)
			#define QGEN_BTOWC(a) qspDirectConvertUC(a, qspCP1251ToUnicodeTable)
			#define QGEN_CHRLWR(a) qspCP1251ToLowerTable[(unsigned char)(a)]
			#define QGEN_CHRUPR(a) qspCP1251ToUpperTable[(unsigned char)(a)]
			#define QGEN_STRCOLL(a, b) qspStrCmpSB(a, b, qspCP1251OrderTable)
		#else
			#define QGEN_FROM_OS_CHAR(a) qspReverseConvertSB(a, qspCP1251ToKOI8RTable)
			#define QGEN_TO_OS_CHAR(a) qspDirectConvertSB(a, qspCP1251ToKOI8RTable)
			#define QGEN_WCTOB(a) qspReverseConvertUC(a, qspKOI8RToUnicodeTable)
			#define QGEN_BTOWC(a) qspDirectConvertUC(a, qspKOI8RToUnicodeTable)
			#define QGEN_CHRLWR(a) qspKOI8RToLowerTable[(unsigned char)(a)]
			#define QGEN_CHRUPR(a) qspKOI8RToUpperTable[(unsigned char)(a)]
			#define QGEN_STRCOLL(a, b) qspStrCmpSB(a, b, qspKOI8ROrderTable)
		#endif
	#endif

	#ifdef _WINDOWS
		#define QGEN_PATHDELIM QGEN_FMT("\\")
	#else
		#define QGEN_PATHDELIM QGEN_FMT("/")
	#endif

	#define QGEN_LEN(x) (sizeof(x) / sizeof(QGEN_CHAR) - 1)

	#define QGEN_CODREMOV 5
	#define QGEN_SPACES QGEN_FMT(" \t")
	#define QGEN_STRSDELIM QGEN_FMT("\r\n")
    #define QGEN_GAMEID QGEN_FMT("QSPGAME")
    #define QGEN_VER QGEN_FMT("0.0.1 alpha 1")
	#define QGEN_NAME QGEN_FMT("QGEN")
	#define QGEN_PASSWD QGEN_FMT("No")
	#define QGEN_MAXACTIONS 50
	#define QGEN_MAXFOLDERNAMELEN 100
	#define QGEN_MAXLOCATIONNAMELEN 100
	#define QGEN_MAXACTIONNAMELEN 500
	#define QGEN_DELIMS QGEN_FMT("():=+-*/<>!&,[] '\"\t{}%@#^;.?~\\|\r\n")
	#define QGEN_BOM "\xFF\xFE"

	/*
	#define wxGetBitmapFromMemory(name) _wxGetBitmapFromMemory(name ## _png, sizeof(name ## _png))
		inline wxBitmap _wxGetBitmapFromMemory(const unsigned char *data, int length)
		{
			wxMemoryInputStream is(data, length);
			return wxBitmap(wxImage(is, wxBITMAP_TYPE_ANY, -1), -1);
		}

	*/

	namespace Ui
	{
		class Controls;

		bool qspOpenQuest(const QGEN_CHAR *fileName, QWidget *parent, Controls *controls, QString &password, bool merge);
		//bool qspSaveQuest(const QGEN_CHAR *fileName, const wxString &passwd, Controls *controls);
		//bool qspExportTxt(const QGEN_CHAR *fileName, Controls *controls);
		//bool qspExportTxt2Game(const QGEN_CHAR *fileName, Controls *controls);
		//bool qspImportTxt2Game(const QGEN_CHAR *fileName, Controls *controls);

		//bool OpenConfigFile(DataContainer *container, const wxString &file);
		//bool SaveConfigFile(DataContainer *container, const wxString &file);
	} // namespace Ui	

#endif // _QGEN_GAME_H_
