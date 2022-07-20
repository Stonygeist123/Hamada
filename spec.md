# Primitives

## Numbers

Signed numbers: i8, i16, i32, i64
Unsigned numbers: u8, u16, u32, u64 + usize, isize (Architecture specific size)
Floating point data types: f32 single precision, f64 double precision

## Strings

Default representation is in a wrapper. String wrapper:

- Len: usize

## Arrays

Representation is in a wrapper.
Array wrapper:

- Len: usize

## Boolean

Either `true` or `false`.
Type: `bool`

# Syntax

## Identifier (id)

```
General:
[a-Z|_][a-Z|0-9|_]...
```

## Expression (expr)

```
Expresion is syntax which yields a value.

General:
<call> | <int> | <float> | <string> | <bool> | <arr>
| <map> | <binop> | <unop> | <ternary> | <assign>
| <range>

```

## Call (call)

```

General:
<identifier> <([<expr>,]...)>

```

## Assignment (assign)

```

Usage:
x = 2

General:
<identifier | index> = <expr>

```

## Array literal (array)

```

[[<expr>][,<expr>]...[,]]

```

## Index signature (index)

```

With array:
<arr>[<int | float>]

With map:
<map>[expr]

```

## Map literal (map)

```

Usage:
{
	"x": 2,
	"y": "Hi"
}

General:
{[<expr>: <expr>][,<expr>: <expr>]...[,]}

```

## String literal (string)

```
Usage:
"text"

General:
"<text>"

```

## Integer literal (int)

```
Usage:
100
0x1a0
0b100
0o100
1_000
10e10

General:
[0x[0-f|_]...] | [0b[0|1|_]...] | [0o[0-8|_]...] | [[0-9|_]...[e[0-9]...]]
```

## Float literal (float)

```
Usage:
123.456
123_456e-3

General:
[[0-9|_]...[[-]e[0-9]...]]
```

## Bool literal (bool)

```
Usage
true
false

General:
<true> | <false>
```

## Binary operations (binop)

```
Usage:
1 + 2
a += b

General
<expr>
[
  '||'
  | &&
  | ==
  | !=
  | >=
  | >
  | <
  | <=

] | [

  <<
  | >>
  | '|'
  | &
  | ^
  | +
  | -
  | *
  | /
  | %
  | **
[=]
]
<expr>
```

## Unary operator (unop)

```
Usage:
-f
~i
(int)b

General:
[
  -
  | ~
  | !
  | (<type>)
  <expr>
] | [
  <expr>
  '[' <expr> ']'
  | ++
  | --
  | as <type>
]
```

## Ternary operator (ternary)

```
Usage:
x ? y : z

General:
<expr> ? <expr> : <expr>
```

## Type (type)

```

General:
<identifier>

```

## Range (range)

```

Usage:
1..100
5..=10

General:
<int>..[=]<int>

```

## Statement (stmt)

```
Statement is any executable amount of code.
Might be a scope aswell.

General:
<scope> | <if> | <for> | <while> | <expr> | <decl>
```

## Scope (scope)

```
General:
{
  [<stmt>]...
}
```

## Variable declaration (decl)

```

Infered type:
var x = <expr>

Explicit type:
var x: <type> = <expr>

Mutable declaration:
var x = <expr>

Constant decleration:
const x = <expr>

General:
Using var:
var <id>[: <type>] = <expr>

Using const:
const <id>[: <type>] = <expr>

```


## If statements (if)

```

Usage:
Without else:
if x == 1 { }

With else:
if x == 1 { }
else { }

General:
Without else:
if <expr> <scope>

With else:
if <expr> <scope>
else <scope>

```


## While statements (while)

```

Usage:
With condition:
while !done { }

Without condition:
while { }

General:
With condition:
while <expr> <scope>

Always true:
while <scope>

```


## Do-while statements (while)

```

Usage:
do { }
while x > 2e-3

General:
do <scope> while <expr>

```

## For-Range statements (for)

```

Usage:
Standart:
for const i = 0; i < 100; ++i { }

Range based:
for const i in 1..100 { }

General:
Standart for-loop:
for <decl | assign>; <expr>; <assign> <scope>

Range based for-loop:
for <const | var> <identifier> : <arr | range> <scope>
for <const | var> <identifier> in <arr | range> <scope>

```

## Parameter list (params)

```

Usage:
Without const:
(name: string, n: int)

With const:
(const name: string, n: int)

General:
Typed:
([[const] <id>: <type>,]...)
Untyped:
([[const] <id>[: <type>,]...)

```

## Function declaration (fdecl)

```

Usage:
Without parameter lists:
fn x -> bool { }

With parameter list:
fn x(const name: string) -> void { }

General:
fn <identifier> [params] -> <type> <scope>

```