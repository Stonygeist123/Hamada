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
<call> | <lambda> | <int> | <float> | <string> | <bool>
| <array> | <map> | <binop> | <unop> | <ternary> | <assign>

```

## Call (call)

```

General:
<identifier> <([<expr>,]...)>

```

## Assignment (assign)

```

<identifier> = <expr>

```

## Array expr (array)

```

[[<expr>][,<expr>]...[,]]

```

## Map expr (map)

```

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
!b

General:
[
  -
  | ~
  | !
  | (Type)
  <expr>
] | [
  <expr>
  '[' <expr> ']'
  | ++
  | --
  | as Type
]
```

## Ternary operator (ternary)

```
Usage:
x ? y : z

General:
<expr> ? <expr> : <expr>
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
var x: Type = <expr>
Mutable declaration:
var x = <expr>
Constant decleration:
const x = <expr>

General:
Using var:
var <id>[: Type] = <expr>
Using const:
const <id>[: Type] = <expr>

```


## If statements (if)

```

Without else:
if <expr> <scope>

With else:
if <expr> <scope>
else <scope>

```


## While statements (while)

```

With condition:
while <expr> <scope>

Always true:
while <scope>

```

## For-Range statements (for)

```

for [const] <identifier>

```

## Parameter list (params)

```

General:
Typed:
([[const] <id>: Type,]...)
Untyped:
([[const] <id>[: Type],]...)

```

## Function declaration (fdecl)

```

General:
fn <identifier> [params] -> <Type> <scope>

```