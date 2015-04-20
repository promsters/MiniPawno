#define MP_VERSION "0.1"
#define CONFIG_FILEPATH "minipawno/config.ini"

new MySQL;


// Struktura <Setting>
enum e_settings
{
	setting_mysql_hostname[20],
	setting_mysql_username[20],
	setting_mysql_password[30],
	setting_mysql_database[15],
}
new Setting[e_settings];
