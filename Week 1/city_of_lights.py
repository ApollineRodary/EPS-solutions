lights = int(input())
uses = int(input())
numbers = [int(input()) for _ in range(uses)]

lights_off = 0
max_lights_off = 0
light_states = [False for _ in range(lights)]

for i in numbers:
    for j in range(i-1, lights, i):
        light_states[j] = not light_states[j]
    lights_off = sum(light_states)
    if lights_off > max_lights_off:
        max_lights_off = lights_off
print(max_lights_off)