# tmux notes


## tmux teaching notes
* create three windows
  * work_edit
  * homedir
  * emacs -> students questions and todo_later


## hotkey default
<c>-b


## start session
tmux new -s s1
## from within tmux
:new -s s2


## list sessions
tmux ls


## rename session
hotkey + $

## list windows
*  list/select windows:  hotkey +  w



## detach
hotkey + d

## reatach
tmux attach -d -t s1


## kill session
tmux kill-session -t [name]


## create window
* create: hotkey +  c

## next, previous
* next: hotkey +  n
* prev: hotkey +  p

## rename window
* name: hotkey +  ,


## delete window
hotkey + &

## sessions
* list/select sessions:  hotkey +  s


## panes (windows divided into parts)
* vertical div: hotkey +  "
* horizontal div: hotkey +  %
* switch to pane: hotkey +  o
* swap panes: hotkey +  <c>-o
* change layout: hotkey +  <space>
* zoom pane:  hotkey +  z
* move left: hotkey+{
* move right: hotkey+}
* show pane numbers: hotkey +  q

## switch to pane
hotkey +  NUM

## pane
* kill hotkey +  x
