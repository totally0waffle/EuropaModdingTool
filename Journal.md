# Development Journal
## come here for any updates on the project, I will try and update this per night of commits

(2025-08-07 @ 1:41pm MST)
Currently the biggest hurdle with this project is finding the time to accomplish all of the things I want to do (cliche being that this journal is the first commit in 3 weeks). On next commit I think it may be of some value to stage actual releases using currently working build binaries.
This probably won't work properly out of its build environment however, on the release notes I will atleast try and bundle the hardware information so that the requirements aren't a complete question mark. Hopefully this week and the next coming I will be able to finish the readme, especially this weekend
I plan on dumping a ton of time into this project with the sole goal of finishing its TUI implementation, I will eventually move this implementation to its own seperate branch once I begin work on the graphical version of the project

(2025-08-26 @ 9:30pm MST)
This project is going nowhere as it stands right now, I started a new job (dont worry not in either of my fields of study) and it is sucking all the joy from my life already. My free time has pretty much been thrown out the window as im being pushed to do after hours (non-paid) schooling on a topic I despsise, let alone I have never been comfortable waking up early in the mornings. I probably am just not going to do the schooling shit and face the lashings from my boss. I really want to work on this project again and see it to the end but as it stands I just don't have the time or drive, weekdays are an exhausted delerious mess and the weekends I would rather not even look at a computer at all. It doesn't help the the internet has been in a terrible state for sometime and hardware is only getting more and more expensive with little to no change, I think my love for computers is dying and there is no one to blame but the greedy fucks that run eveything (Microsoft, Google, Nvidia, Intel, OpenAI, Facebook (meta for the cucks), hell even twitter is a baren shithole). I am just as much to blame I keep my code on this shitty microsoft run git frontend and consume pretty much only youtube.
The internet as a community has lost and the only people we can blame are ourselves, our parents, our friends, our families, and the greedy fucks who have pushed control of the community away from the community. The internet will only continue to get worse when google dissolves and a power vacuum is created, thats when total enshitification happens. If I could suggest one thing to the people I know and care about who share my hatred, follow some of my steps: 
- Remove windows from your pc, swap to something like BSD or certain linux distros (arch & debian are my gotos)
- remove chrome (replace with projects like ungoogled chromium if you need it)
- dont use google search or gmail (try alternatives like proton)
- do not browse without an adblock, anti-tracker, vpn and clearing your cookies often
- if a service is free it usually is too go to be true
- replace firefox (use something like palemoon or librewolf, I use the latter)
- Avoid anything unreal 5 (lazy work should not be rewarded)
- ditch spotify and learn to "borrow" your music with plex for ex
- build your pc with components that have functional open source drivers
- avoid AI like its diseased
- this ones a bonus, but ditch discord and move over to self hosted teamspeak or any other self hosted communication service

This wont make you happy but it atleast gives you some comfort in saying you atleast did something to say fuck those companies, instead of simply giving up and taking it.
I know steam has its problems as well but atleast valve is willing to contribute to the open source community and actively trying to make the PC community a better place, hell gabe even is willing to reply to fans via email and dump fortunes into underwater research. Once that man dies I think valve will die with him sadly.

Knowing this is the state of th internet alongside how terrible the state of my country (cananda) is I genuinely consider that suicide may be the only path in life for me. I wasted the first 5 years of my adult life persuing what I love only to be hit by covid, then a global recession (if you dont see it you are part of the problem), and a job market crash which hasn't been seen since the depression. It feels like my entire life has been for nothing I cant envision a future for myself and I can only see it getting worse and worse as time goes on. I don't wanna keep living in this hellhole we call a society, so I do everything I can to self destruct. I will take myself out before I am turned into either a corporate fleshlight or a body bag in some world conflict.
This will be the only and last journal entry covering a personal topic here. If I find the time during my day I will create a dedicated repo for it specifically. Don't expect many changes to come for a while, I am genuinely sorry to dissapoint anyone.

(2025-11-14 @ 12:13pm MST)
Im gonna go back and refactor a bunch of code, aswell as scrap the TUI idea. This project needs a proper gui so in order to get that part of my plan accomplished im gonna try and learn/use QT being that it should be usable on all os's even if my code is kinda hardwired for linux specifically right now. In future im gonna be smarter about building for multi-os. This project should pick up some steam now that winter has hit and that I am considering quitting this position just due to mental health reasonings. If that does become the case projects like this will become my full time gig.

Currently my next steps are as follows:
- [ ] [Replace User interface](https://github.com/totally0waffle/EuropaModdingTool/issues/1)
- [ ] [Refactor Directory System](https://github.com/totally0waffle/EuropaModdingTool/issues/1)
- [ ] [Compile Modifier Variables](https://github.com/totally0waffle/EuropaModdingTool/issues/1)
- [ ] [Compile Culture List](https://github.com/totally0waffle/EuropaModdingTool/issues/1)
- [ ] [Compile Religion List](https://github.com/totally0waffle/EuropaModdingTool/issues/1)
- [ ] [Compile Province List](https://github.com/totally0waffle/EuropaModdingTool/issues/1)

The compilations are for in app runtime compilations as all of those values I plan on being modifiable and editable even if they are stored in various places its better that they can be edited at runtime rather than have them hardcoded directly into the app like the modifiers and traits.
