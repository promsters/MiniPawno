new sprintfStr[1000];

#define sprintf(%0,%1) (format(sprintfStr, 1000, %0, %1), sprintfStr)