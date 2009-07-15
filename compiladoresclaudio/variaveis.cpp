#define MAX_TAB_SIMB 1024
#define MAX_TAB_FUNC 1024
#define MAX_TAB_PARAM 1024

int N_SIMB=0;
int N_FUNC=0;
int N_PARAM=0;

int N_TEMP=0;
int N_LABEL=0;

int PARAM_POSITION;

string TEMP_CODIGO;

struct atributo
{
	string v,t,c;
};

struct tipo_operacao
{
	string op,a,b,res;
} tab_operadores[]=
{
	
//ARITMETICOS
	{"+","int","int","int"},
	{"+","int","real","real"},
	{"+","real","int","real"},
	{"+","real","real","real"},
	{"+","string","string","string"},
	{"+","string","char","string"},
	{"+","char","string","string"},
	{"+","char","char","string"},
	{"-","int","int","int"},
	{"-","int","real","real"},
	{"-","real","int","real"},
	{"-","real","real","real"},
	{"/","int","int","int"},
	{"/","int","real","real"},
	{"/","real","int","real"},
	{"/","real","real","real"},
	{"*","int","int","int"},
	{"*","int","real","real"},
	{"*","real","int","real"},
	{"*","real","real","real"},
	{"%","int","int","int"},
	{"%","int","real","real"},
	{"%","real","int","real"},
	{"%","real","real","real"},
	{"DIV","int","int","int"},
	{"DIV","int","real","int"},
	{"DIV","real","int","int"},
	{"DIV","real","real","int"},
	
//RELACIONAIS
	{"<","int","int","bool"},
	{"<","int","real","bool"},
	{"<","real","int","bool"},
	{"<","real","real","bool"},
	{">","int","int","bool"},
	{">","int","real","bool"},
	{">","real","int","bool"},
	{">","real","real","bool"},
	{"<=","int","int","bool"},
	{"<=","int","real","bool"},
	{"<=","real","int","bool"},
	{"<=","real","real","bool"},
	{">=","int","int","bool"},
	{">=","int","real","bool"},
	{">=","real","int","bool"},
	{">=","real","real","bool"},
	{"==","int","int","bool"},
	{"==","int","real","bool"},
	{"==","real","int","bool"},
	{"==","real","real","bool"},
	{"==","char","char","bool"},
	{"==","char","string","bool"},
	{"==","string","char","bool"},
	{"==","string","string","bool"},
	{"==","bool","bool","bool"},
	{"!=","int","int","bool"},
	{"!=","int","real","bool"},
	{"!=","real","int","bool"},
	{"!=","real","real","bool"},
	{"!=","char","char","bool"},
	{"!=","char","string","bool"},
	{"!=","string","char","bool"},
	{"!=","string","string","bool"},
	{"!=","bool","bool","bool"},

//ATRIBUICAO
	{"=","int","int","int"},
	{"=","real","real","real"},
	{"=","real","int","real"},
	{"=","char","char","char"},
	{"=","string","string","string"},
	{"=","string","char","string"},
	{"=","bool","bool","bool"},
	
//LOGICO
	{"&&","bool","bool","bool"},
	{"||","bool","bool","bool"},
	{"!","","bool","bool"},

	{"num deu !","","",""}
};

struct novoId
{
	string valor;
	string tipo;
	int n_dim;
	int xsize;
	int ysize;
	string func;
	string func_tipo;
	bool retornou;
} ID_NOVO;

struct chamaFunc
{
	string nome;
	string tipo;
	string retorno;
} FUNC_CHAMA;

struct simbolo
{
	string nome;
	string tipo;
	string func;
	int tamanho;
	int n_dim;
	int xsize;
	int ysize;
} tab_simb [MAX_TAB_SIMB];

struct funcao
{
	string nome;
	string tipo;
} tab_func [MAX_TAB_FUNC];

struct parametro
{
	string nome;
	string tipo;
	string func;
	int posicao;
} tab_param [MAX_TAB_PARAM];
