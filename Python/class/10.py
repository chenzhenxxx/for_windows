s=input()
sum=0
x=0
begin=0
end=len(s)-1
tmp=""
while True:
    tmp+=s[begin]
    sum+=1
    begin=begin+1
    if sum==len(s):
        break
    tmp+=s[end]
    sum+=1
    end=end-1
    if sum==len(s):
        break

print(tmp)
     

