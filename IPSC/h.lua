my_bool = 0
local cnt=0
for i=1,13 do
  if i!=myself and colors[i]==1 then
    cnt=cnt+1
if (cnt%2==0) then
  my_bool=1
hands = raise(my_bool)

local ccnt=0
my_bool=0
for i=1,13 do
  if i!=myself and hands[i]==1 then
    ccnt=ccnt+1
if (ccnt%2==0) then
  my_bool=1

if my_bool then
  answer = 1
else
  answer = 2
end
