#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

void clear_term();
int kbhit(void);

int main()
{
	clear_term(); // optional to delete

	const char *c[5];
	c[0] = "\
                                    `:.                                                             \n\
                               .-sdys+`                                                             \n\
                            `-yNNNo`                                                                \n\
                          -hmNMmo.                                                                  \n\
                      `/+hNMMmo-                                                                    \n\
                     -yMMMMms-               `` -:                                                  \n\
                   -hNMMMmo`            `/so:.``:.                                                  \n\
                  -dMMMN+.             :-:.`  `h/                                                   \n\
                -ymMMN+.            `:::      `m/                                                   \n\
               -hMMMNo             :ssosss/-`  :/.                                                  \n\
             `oNMMMh:              ./yNMMMMNs.` /:                                                  \n\
            .oMMMMm-               .oMMMMMMMNNh` +.                                                 \n\
            oMMMMMo                sNNN_NMM\\_Mm` `::......`                                         \n\
           -mNyos/.                +o+dNMMMMNMm`   `-----+/                                         \n\
           .ymmNs.`                 -/.hMMMMMMm`         :/                                         \n\
            ``-sydmo:.`             .- `mMMMMNd`    `:::`:/                                         \n\
                 .omm:-.           //   mMMmo-.  `--oMMN-:+                                         \n\
                   sm/dms-         ..  `mN+.     sNmmMMM::/                                         \n\
                   -/.-+sms-           -+-       sy:/NMN-:/                                         \n\
                     ...:syo/+:-`..              :`  :ds.:/                                         \n\
                       `   `-ohhyd+`                  /N+o+                                         \n\
                            .yo`:yNhs:`    ```        `/yNo                                         \n\
                             -/- `ohosy+/..-odo``` `/:.-`//                                         \n\
                               `.-.o+ -:sy+.+NMdh/  ..   ./-                                        \n\
                                   yy   +/ss:/s+y:        :s                                        \n\
                                   yy   :. `` .`/-         ```                                      \n\
                                   yy      `. `/..` --``-o/ --                                      \n\
                                   +/               +hsshm+`s`..`                                   \n\
                                    .-                `` -++m+y/-`                                  \n\
                                    ./:                    `/`                                      \n\
                                     .o`                     +                                      \n\
                                     .o`                     o                                      \n\
                                     -h`                     -+.                                    \n\
                                      `+`                    `/s.                                   \n\
                                       `o-                     `o:                                  \n\
                                        --` ``            ``````-/-                                 \n\
                                         `/:..+oooo.   /o:-------sd/                                \n\
                                              ````` `- ``         -/                                \
";
	c[1] = "\
                                                                                                    \n\
                                                                                                    \n\
                                                                                                    \n\
                                                                                                    \n\
                                           `:////////////////:                                      \n\
                                    `.:oyyydMMNhmMMMMNhhhhhhhh+//.                                  \n\
                               ``/yhdNMMMMNmy:-.++:--.`     ``  `                                   \n\
                            `+smNNMMMMNMo/.`  `h/                                                   \n\
                          `oddMMMMMdhdo+      `m/                                                   \n\
                          `hNs+mdhooyyssss/-`  :/.                                                  \n\
                           -yd+/`` ./yNMMMMNs.` /:                                                  \n\
                            `ym.   .oMMMMMMMNmh``+.                                                 \n\
                             :No`` sNNN_NMM\\_Mm` `::......`                                         \n\
                             +Mh/. +o+dNMMMMNMm`   `-----+/                                         \n\
                            .y++/-. -/.hMMMMMMm`         :/                                         \n\
                            `:   +: .- `mMMMMNd`    `:::`:/                                         \n\
                             .s-.ymh+   mMMmo-.  `--oMMN-:+                                         \n\
                             `--.-oNs  `mN+.     sNmmNMM::/                                         \n\
                                   ys  -+-       sy+:.od-:/                                         \n\
                                 `.+y/           /`./- .`:+                                         \n\
                                 /- -d+            `-o   :+                                         \n\
                                 `-``od.          `:-    :/                                         \n\
                                  :- .os`        `o/     :/                                         \n\
                                  `o+ `h/`       :-`     ./-                                        \n\
                                   yy  /m/-+: ..::`       :s                                        \n\
                                   yy  `:.`:/`oNy.          ``                                      \n\
                                   yy .o..:.`-om:           -:                                      \n\
                                   //`odyh-`:/o-`          `y`                                      \n\
                                    .-  `.``-//            `y`                                      \n\
                                    ./:       -/.           :`                                      \n\
                                     .o`       h:            +                                      \n\
                                     .o`       `:-````       o                                      \n\
                                     -h`        .:-oy.       -+.                                    \n\
                                      `+`         .:.        `/s.                                   \n\
                                       `o.        /s///-       `o:                                  \n\
                                        --` ``            ``````-/-                                 \n\
                                         `/:..+oooo.   /o:-------sd/                                \n\
                                              ````` `- ``         -/                                \
";
	c[2] = "\
                                    `:.                                                             \n\
                               .-sdys+`                                                             \n\
                            `-yNNNo`                                                                \n\
                          -hmNMmo-                                                                  \n\
                      `/+hNMMmo.                                                                    \n\
                     :hMMMMms.               `` -:                                                  \n\
                   -hNMMMmo`            `/so:.``:-                                                  \n\
                  -dMMMm+`             :-:.`  `h/                                                   \n\
                -ymMMm+.            `::/      `m/                                                   \n\
               -hMMMN+             :ssosss/-`  :/.                                                  \n\
             `oNMMMh:              ./yNMMMMNs.` /:                                                  \n\
            .oMMMMd.               .oMMMMMMMNNh``+.                                                 \n\
            oMMMMM+                sNNN_NMM\\_Mm` `::......`                                         \n\
           -mNyss/`                +o+dNMMMMNMm`   `-----+/                                         \n\
           .ymmNs.`                 -+.hMMMMMMm`         :/                                         \n\
             `.oydmo:.`             .- `mMMMMNd`    `:::`:/                                         \n\
                 -smd:-.           //   mMMNo-.  `--oMMN-:+                                         \n\
                   sd/dNy-         ..  `mN+.     sNmNMMM::/                                         \n\
                   -/.-+sms-           .+-       sy:/NMN-:/                                         \n\
                     ...-syo/o/-`..              :`  :do.:+                                         \n\
                       `   `-shhym+`                  /m+++                                         \n\
                            `so`:yNhs/`    ```        `/ym+                                         \n\
                             ./- `ohooyo+.`-od+``  `/:.-.//                                         \n\
                               `.-`++ -:sy+.+NMdh/ `-.   ./-                                        \n\
                                   yy   ++ss:/y+y:        :s                                        \n\
                                   yy   /- `` `./-          .`                                      \n\
                                   yy      `. .+.-``--``-o/ --                                      \n\
                                   /+         `    `/hyshm+`s````                                   \n\
                                    .-                   -o+m+s/.`                                  \n\
                                    ./:                    `/`                                      \n\
                                     .o`                     +                                      \n\
                                     -o`                     o                                      \n\
                                     -h`                     -+.                                    \n\
                                      `+`                    `/s.                                   \n\
                                       `o.                     `o:                                  \n\
                                        --` ``            ``````-/-                                 \n\
                                         `/:..+oooo.   /o:-------sd/                                \n\
                                              ````` `- ``         -/                                \
";
	c[3] = "\
                                                                                                    \n\
                                                                                                    \n\
                                                                                                    \n\
                                                                                                    \n\
                                               -/:                                                  \n\
                                             `.-+:                                                  \n\
                                        `/so:` /.                                                   \n\
                                       :-:.`  `m/                                                   \n\
                                    `:::      `m/                                                   \n\
                                   :ysosso:-`  :/.                                                  \n\
                                   ./yNMMMNNo.` /:                                                  \n\
                                   .oMMMMMMMNmd``+.                                                 \n\
                                   sNNN_NMM\\_Mm` `:-......`                                         \n\
                                   /o+dNMMMMNMm`   `-----+/                                         \n\
                                    -+.hMMMMMMm`         :/                                         \n\
                                    .- `mMMMMNd     `:::`:/                                         \n\
                                   :/   mMMm+..  `--oNMN-:/                                         \n\
                                   ..  `mN+.     sNmNMMM::/                                         \n\
                                       .+-       sy:-sNM://                                         \n\
                                 `.  `-          :`   -syms                            `::.         \n\
                                 ++  :h`+o.             .sms.                          `:/-/so-`    \n\
                                 .y/ :m+::`              :h+y/`                            -NMNh-   \n\
                 .               /my../. ` `/+++../-     :/ ``--`                          -NMMMN+  \n\
                 ` `` `          -+y+      `--:myyd++s/:://-   `-://///:`                `+dMMMMMs  \n\
                      `  -```     .hy ......-////yyss/:::-oh+//./dmymoomd-             `/hMMMMMMm+  \n\
                           `.  `  `yy /+oo++-`    ``       `.` `shsoydyNNy/-----` ````:hMMMMMMmm-   \n\
                                  -my .--````   ``          -:  `.. -``+/:+.```` `+oooyhdNmhhd.`    \n\
                                   +/ ...:osys`shy.    ....:y`                      `   `.`  `      \n\
                                    .-      .-`:/s+`  :hmh:+h``.  ........`   /o.  `o`              \n\
                                    .//                 ::  :`-/``sddmds++.   :o-                   \n\
                                     .o`                     +     ````                             \n\
                                     -s`                    `s                                      \n\
                                     -h`                     -+.                                    \n\
                                      `+                     `/s`                                   \n\
                                      `s`                      ::`                                  \n\
                                       .+.              ````````h+                                  \n\
                                        hy``ooooo.```+oo-------/No                                  \n\
                                         `  ````-///.```       `/+`                                 \
";
	c[4] = "\
                                                                                                    \n\
                                                                                                    \n\
                                                                                                    \n\
                                                                                                    \n\
                                               -/:                                                  \n\
                                             `.-+:                                                  \n\
                                        `/so:` /.                                                   \n\
                                       :-:.`  `d/                                                   \n\
                                    `:::      `m/                                                   \n\
                                   :ysosso:-`  :/.                                                  \n\
                                   ./yNMMMNNo.` /:                                                  \n\
                                   .oMMMMMMMNmd``+.                                                 \n\
                                   sNNN_NMM\\_Mm` `:-......`                                         \n\
                                   /o+dNMMMMNMm`   `-----+/                                         \n\
                                    -+.hMMMMMMm`         :/                                         \n\
                                    .- `mMMMMNh     `:::`:/                                         \n\
                                   :/   mMMm+..  `--oNMN-:/                                         \n\
                                   ..  `mN+.     sNmNMMM::/                                         \n\
                                       .+-       sy:-sNM://                                         \n\
                                 `.  `-          :`   -syms                            `::.         \n\
                                 ++  :h`+o.             .sms.                          `:/-/so-`    \n\
                                 .y/ :m+::`              :h+y/`                            -NMNh-   \n\
                                 /my../. ` `/+++../-     :/ ``--`                          -NMMMN+  \n\
                                 -+y+      `--:myyd++s/:://-   `-::////:`                `/dMMMMMs  \n\
                                  .hy ......-////yyss/::::oh+//./dmymoomd-             `/hMMMMMMm+  \n\
                                   yy /+oo+o-`    ``       `.` `shsoydyNNy/-----` ````:hMMMMMMmm-   \n\
                                   yy                       -:  `.. -``+/:+.```` `+oooyhhhhhhy.`    \n\
                                   /+                      `s`                                      \n\
                                    .-                     `s`                                      \n\
                                    .//                     :`                                      \n\
                                     .o`                     +                                      \n\
                                     -s`                    `s                                      \n\
                                     -h`                     -+.                                    \n\
                                      `+                     `/s`                                   \n\
                                      `s`                      ::`                                  \n\
                                       .+.              ````````h+                                  \n\
                                        hy``ooooo.```+oo-------/No                                  \n\
                                         `  ````-///.```       `/+`                                 \
";

	char input[1];

//	for (int i = 0; i <= 100; i++)
	int i = 0;
	while(!kbhit())
	{

		printf("%s", c[i]);
		fflush(stdout);
		usleep(200000);

		if (i == 4)
			i = 0;
		else
			i ++;

		clear_term();
	}
	return 0;
}

void clear_term()
{
	for (int i = 0; i < 41; i++){
		write(1,"\33[2K\r",5);
		write(1,"\33[1A",4);
	}
	write(1,"\33[2K\r",5);
}

//KBHit function by itsme86 on cboard.cprogramming.com
int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;
 
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
  ch = getchar();
 
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
 
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
 
  return 0;
}