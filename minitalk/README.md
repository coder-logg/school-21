# minitalk

## Общие инструкций
* Ваш проект должен быть написан в соответствии с Нормой. Если у вас есть бонусные файлы / функции,
  они включаются в проверку нормы, и вы получите 0, если внутри есть ошибка нормы.
* Ваши функции не должны завершаться неожиданно (ошибка сегментации, ошибка шины, двойное
  освобождение и т.д.), за исключением неопределенного поведения. Если это произойдет, ваш проект
  будет считаться нефункциональным и получит 0 во время оценки.
* Все пространство памяти, выделенное кучей, должно быть должным образом освобождено при необходимости.
  Утечки недопустимы.
* Если субъект требует этого, вы должны отправить Makefile, который скомпилирует ваши исходные файлы 
  в требуемый вывод с флагами -Wall, -Wextra и -Werror, и ваш Makefile не должен повторно связываться.
* Ваш Makefile должен содержать как минимум правила $ (NAME), all, clean, fclean и re.
* Чтобы превратить бонусы в свой проект, вы должны включить бонус правила в свой Makefile, который
  добавит все различные заголовки, библиотеки или функции, запрещенные в основной части проекта.
  Бонусы должны быть в другом файле _bonus. {C / h}.  Оценка обязательной и бонусной части проводится отдельно.
* Если ваш проект позволяет вам использовать ваш libft, вы должны скопировать его исходный
  код и связанный с ним Makefile в папку libft с соответствующим Makefile. Makefile вашего проекта
  должен скомпилировать библиотеку, используя свой Makefile, а затем скомпилировать проект.
* Мы рекомендуем вам создавать программы тестирования для вашего проекта, даже если эту работу не
  нужно будет отправлять и оценивать. Это даст вам возможность легко проверить свою работу и работу
  коллег. Вы найдете эти тесты особенно полезными во время защиты. Действительно, во время защиты
  вы можете использовать свои тесты и / или тесты партнера, которого вы оцениваете.
* Отправьте свою работу в назначенный репозиторий git. Оцениваться будет только работа
  в репозитории git. Если DeepThreadt назначен для оценки вашей работы, это будет сделано после ваших
  оценок коллег. Если во время выставления оценок Deep Threatt в каком-либо разделе вашей работы 
  произойдет ошибка, оценка будет остановлена.
* Исполняемые файлы должны называться `client` и `server`.
* К ошибкам нужно относиться чутко. Ни в коем случае ваша программа не может неожиданно завершиться
  (ошибка сегментации, ошибка шины, двойное освобождение и т.д.).
* Ваша программа не может иметь утечек памяти.
* В обязательной части вам разрешено использовать следующие функции:
    * write
    * signal
    * sigemptyset
    * sigaddset
    * sigaction
    * kill
    * getpid
    * malloc
    * free
    * pause
    * sleep
    * usleep
    * exit
    
## Основная часть
* Вы должны создать коммуникационную программу в виде клиента и сервера. 
* Сервер должен быть запущен первым, а после запуска он должен отображать свой PID.
* Клиент примет в качестве параметров:
  * PID сервера.
  * Строка, которую следует отправить.
* Клиент должен передать строку, переданную в качестве параметра серверу. 
  После получения строки сервер должен ее отобразить.
* Связь между вашими программами должна осуществляться ТОЛЬКО с использованием сигналов UNIX.
* Сервер должен уметь быстро отображать строку. Под быстрым мы подразумеваем, 
  что если вы думаете, что он слишком длинный, то он, вероятно, слишком длинный 
  (подсказка: 1 секунда для 100 символов - КОЛОССАЛЬНО)
* Ваш сервер должен иметь возможность получать строки от нескольких клиентов подряд без перезапуска.
* Вы можете использовать только два сигнала `SIGUSR1` и `SIGUSR2`.
## Бонусная часть
* Добавьте небольшую систему подтверждения приема.
* Поддержка символов Unicode!