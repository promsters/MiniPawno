new LogPrintfStr[200];
#define logprintf(%0,%1,%2) \
						format(LogPrintfStr, 200, %1, %2); \
						_logprintf(%0, LogPrintfStr)

#pragma unused LogPrintfStr
						
stock _logprintf(const file_name[], const string[])
{
	new File:log = fopen(file_name, io_append);
    if(log)
    {
		new date_time[60], Year, Month, Day, Hour, Minute, Second;
		gettime(Hour, Minute, Second);
		getdate(Year, Month, Day);	
		format(date_time, sizeof(date_time), "[%02d.%02d.%02d, %02d:%02d:%02d] ", Day, Month, Year, Hour, Minute, Second);
		
		fwrite(log, date_time);
        fwrite(log, string);
		fwrite(log, "\r\n");
        fclose(log);
    }
}