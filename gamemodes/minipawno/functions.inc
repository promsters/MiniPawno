stock LoadConfiguration()
{
	Code_ExTimer_Begin(LoadConfiguration);
	
	if( !dini_Exists(CONFIG_FILEPATH) ) 
	{
		dini_Create(CONFIG_FILEPATH);
		
		dini_Set(CONFIG_FILEPATH, "mysql_hostname", "127.0.0.1");
		dini_Set(CONFIG_FILEPATH, "mysql_username", "admin");
		dini_Set(CONFIG_FILEPATH, "mysql_password", "admin");
		dini_Set(CONFIG_FILEPATH, "mysql_database", "red");
	}
	
	dini_Get(CONFIG_FILEPATH, "mysql_hostname", Setting[setting_mysql_hostname]);
	dini_Get(CONFIG_FILEPATH, "mysql_username", Setting[setting_mysql_username]);
	dini_Get(CONFIG_FILEPATH, "mysql_password", Setting[setting_mysql_password]);
	dini_Get(CONFIG_FILEPATH, "mysql_database", Setting[setting_mysql_database]);
	
	printf("[MiniPawno] Wczytano konfiguracjê serwera [czas wykonania: %d ms]", Code_ExTimer_End(LoadConfiguration));
}

stock ConnectMysql()
{
	Code_ExTimer_Begin(ConnectMysql);
	
	mysql_log(LOG_ALL);	
	MySQL = mysql_connect(Setting[setting_mysql_hostname], Setting[setting_mysql_username], Setting[setting_mysql_database], Setting[setting_mysql_password]);

	if( mysql_errno(MySQL) )
	{
		printf("[MiniPawno] B³¹d po³¹czenia z baz¹ danych [czas trwania: %d ms]", Code_ExTimer_End(ConnectMysql));
		return false;
	}
	
	printf("[MiniPawno] Po³¹czano z baz¹ danych %s@%s [czas trwania: %d ms]", Setting[setting_mysql_username], Setting[setting_mysql_hostname], Code_ExTimer_End(ConnectMysql));
	return true;
}