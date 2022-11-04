import sys

if __name__ == '__main__':
  tests = [];
  with open(sys.argv[1], 'r') as fin:
    _tests = int(next(fin));
    for i in range(_tests):
      n, m = next(fin).split();
      tests.append([
        n, m,
        [next(fin) for _ in range(int(m))]
      ])

  for i in range(len(tests)):
    with open(f'{sys.argv[2]}/{i}', 'w') as fout:
      fout.write(f'1\n{tests[i][0]} {tests[i][1]}\n');
      fout.writelines(tests[i][2]);
