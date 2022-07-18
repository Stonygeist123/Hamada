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
| <array> | <map> | <binop> | <unop> | <ternary>
```

## Statement (stmt)

```
Statement is any executable amount of code.
Might be a scope aswell.

General:
<scope> | <if> | <for> | <while> | <expr> | <decl> | <assign>
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

## Parameter list (params)

```

General:
Typed:
([<id>: Type,]...)
Untyped:
([<id>[: Type],]...)

```

## TODO: Function decl (func)


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