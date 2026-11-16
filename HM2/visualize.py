
import matplotlib.pyplot as plt


def read_points(filename):
    with open(filename, "r") as file:
        data = file.read().split()

    n = int(data[0])

    points = []
    for i in range(n):
        x = float(data[1 + 2 * i])
        y = float(data[2 + 2 * i])
        points.append((x, y))

    return points


# Читаем исходные точки и результат
input_points = read_points("input.txt")
hull_points = read_points("output.txt")

# Координаты исходных точек
x = [p[0] for p in input_points]
y = [p[1] for p in input_points]

# Координаты выпуклой оболочки
hx = [p[0] for p in hull_points]
hy = [p[1] for p in hull_points]

# Замыкаем контур
if hull_points:
    hx.append(hx[0])
    hy.append(hy[0])

# Рисуем
plt.figure(figsize=(10, 8))

# Все исходные точки
plt.scatter(x, y, color="blue", label="Исходные точки", zorder=2)

# Выпуклая оболочка
plt.plot(hx, hy, color="red", linewidth=2, label="Выпуклая оболочка", zorder=3)

# Вершины оболочки
plt.scatter(hx[:-1], hy[:-1], color="red", s=40, zorder=4)

plt.title("Построение выпуклой оболочки")
plt.xlabel("X")
plt.ylabel("Y")

plt.grid(True)
plt.axis("equal")
plt.legend()

plt.show()
