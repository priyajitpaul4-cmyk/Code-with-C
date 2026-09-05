const CATEGORY_COLORS=['#7c3cff','#218cff','#19c887','#ff9d21','#d45cff','#20d8ff'];
let allPrograms=[],categoryOrder=['All'],activeCategory='All',activeSearch='',showAllPrograms=false;
const FEATURED_PROGRAM_COUNT=6;
const $=s=>document.querySelector(s), $$=s=>document.querySelectorAll(s);
const grid=$('#program-grid'), empty=$('#empty-state'), search=$('#search-input'), categoryNav=$('#category-nav');

const translations={
 en:{home:'Home',programs:'Programs',problems:'Problems',interview:'Interview',about:'About',allPrograms:'All Programs',eyebrow:'Learn · Practice · Build',why:'Why We Learn',cProgramming:'C Programming?',heroText:'C is the foundation of many modern technologies. It helps you understand how computers work, builds problem-solving skills, and is the base for languages like C++, Java, Python and more.',strongFoundation:'Strong Foundation',foundationText:'Builds a strong programming base',efficient:'Efficient & Fast',efficientText:'Fast, small and highly efficient',systemLevel:'System Level',systemText:'Works close to hardware',career:'Career Growth',careerText:'Useful for placements and higher studies',startLearning:'Start Learning C →',viewAll:'View All Programs',aboutCLanguage:'About C Language',aboutCText:'C is a general-purpose, procedural programming language developed by Dennis Ritchie in 1972 at Bell Labs. It is widely used for system programming, application development, and embedded systems.',startingPath:'Starting Path',pathText:'Follow these steps to set up your C programming environment.',installCompiler:'Install Compiler',installIDE:'Install IDE',extensions:'Install Extensions',writeRun:'Write & Run Code',practice:'Practice Regularly',quickTips:'Quick Tips',tip1:'Learn basics of syntax',tip2:'Practice daily',tip3:'Read and analyze code',tip4:'Build mini projects',tip5:'Never stop learning',allCPrograms:'All C Programs',viewAll32:'View All 32 Programs',sampleProblems:'Sample Problem Set',browseProblems:'Browse All Problems',interviewQuestions:'Important Interview Questions',viewQuestions:'View All Questions'},
 bn:{home:'হোম',programs:'প্রোগ্রাম',problems:'সমস্যা',interview:'ইন্টারভিউ',about:'সম্পর্কে',allPrograms:'সব প্রোগ্রাম',eyebrow:'শিখুন · অনুশীলন · তৈরি করুন',why:'কেন আমরা শিখি',cProgramming:'C প্রোগ্রামিং?',heroText:'C আধুনিক প্রযুক্তির অনেক অংশের ভিত্তি। এটি কম্পিউটার কীভাবে কাজ করে বুঝতে এবং সমস্যা সমাধানের দক্ষতা বাড়াতে সাহায্য করে।',strongFoundation:'মজবুত ভিত্তি',efficient:'দ্রুত ও কার্যকর',systemLevel:'সিস্টেম লেভেল',career:'ক্যারিয়ার উন্নতি',startLearning:'C শেখা শুরু করুন →',viewAll:'সব প্রোগ্রাম দেখুন',aboutCLanguage:'C ভাষা সম্পর্কে',startingPath:'শেখার পথ',quickTips:'দ্রুত টিপস',allCPrograms:'সব C প্রোগ্রাম',sampleProblems:'নমুনা সমস্যা',interviewQuestions:'গুরুত্বপূর্ণ ইন্টারভিউ প্রশ্ন'},
 hi:{home:'होम',programs:'प्रोग्राम',problems:'समस्याएँ',interview:'इंटरव्यू',about:'अबाउट',allPrograms:'सभी प्रोग्राम',eyebrow:'सीखें · अभ्यास करें · बनाएं',why:'हम क्यों सीखते हैं',cProgramming:'C प्रोग्रामिंग?',heroText:'C कई आधुनिक तकनीकों की नींव है। यह कंप्यूटर को समझने और समस्या-समाधान कौशल विकसित करने में मदद करता है।',strongFoundation:'मजबूत नींव',efficient:'तेज़ और कुशल',systemLevel:'सिस्टम लेवल',career:'करियर विकास',startLearning:'C सीखना शुरू करें →',viewAll:'सभी प्रोग्राम देखें',aboutCLanguage:'C भाषा के बारे में',startingPath:'शुरुआती मार्ग',quickTips:'त्वरित टिप्स',allCPrograms:'सभी C प्रोग्राम',sampleProblems:'नमूना समस्याएँ',interviewQuestions:'महत्वपूर्ण इंटरव्यू प्रश्न'},
 es:{home:'Inicio',programs:'Programas',problems:'Problemas',interview:'Entrevista',about:'Acerca de',allPrograms:'Todos los programas',eyebrow:'Aprende · Practica · Construye',why:'¿Por qué aprendemos',cProgramming:'programación C?',startLearning:'Empezar a aprender C →',viewAll:'Ver todos los programas',aboutCLanguage:'Sobre el lenguaje C',startingPath:'Ruta inicial',quickTips:'Consejos rápidos',allCPrograms:'Todos los programas C',sampleProblems:'Problemas de práctica',interviewQuestions:'Preguntas importantes de entrevista'},
 fr:{home:'Accueil',programs:'Programmes',problems:'Problèmes',interview:'Entretien',about:'À propos',allPrograms:'Tous les programmes',eyebrow:'Apprendre · Pratiquer · Construire',why:'Pourquoi apprendre',cProgramming:'le C ?',startLearning:'Commencer à apprendre le C →',viewAll:'Voir tous les programmes',aboutCLanguage:'À propos du langage C',startingPath:'Parcours de départ',quickTips:'Conseils rapides',allCPrograms:'Tous les programmes C',sampleProblems:'Problèmes pratiques',interviewQuestions:"Questions d'entretien importantes"},
 de:{home:'Startseite',programs:'Programme',problems:'Aufgaben',interview:'Interview',about:'Über uns',allPrograms:'Alle Programme',eyebrow:'Lernen · Üben · Bauen',why:'Warum lernen wir',cProgramming:'C-Programmierung?',startLearning:'C lernen →',viewAll:'Alle Programme',aboutCLanguage:'Über die Sprache C',startingPath:'Lernpfad',quickTips:'Schnelle Tipps',allCPrograms:'Alle C-Programme',sampleProblems:'Beispielaufgaben',interviewQuestions:'Wichtige Interviewfragen'}
};

let problems=[],questions=[];

async function init(){
 try{const r=await fetch('data.json');if(!r.ok)throw Error('data.json not found');allPrograms=await r.json();}
 catch(e){allPrograms=[];grid.innerHTML='<p class="empty-state">Could not load data.json. Make sure it is next to index.html.</p>';}
 try{const r=await fetch('Problems/sample-problems.json');if(!r.ok)throw Error('sample-problems.json not found');problems=await r.json();}
 catch(e){problems=[];}
 try{const r=await fetch('Interview/interview-questions.json');if(!r.ok)throw Error('interview-questions.json not found');questions=await r.json();}
 catch(e){questions=[];}
 buildCategories();renderCategories();renderPrograms();renderProblems();renderQuestions();setupUI();observeReveal();updateProgress();
}
function buildCategories(){const seen=new Set();allPrograms.forEach(p=>{if(!seen.has(p.category)){seen.add(p.category);categoryOrder.push(p.category)}});$('#program-count').textContent=allPrograms.length||32;}
function renderCategories(){categoryNav.innerHTML=categoryOrder.map((c,i)=>`<button class="category-btn ${c===activeCategory?'active':''}" data-cat="${esc(c)}">${esc(c)}</button>`).join('');$$('.category-btn').forEach(b=>b.onclick=()=>{activeCategory=b.dataset.cat;renderCategories();renderPrograms()});}
function renderPrograms(){const filtered=allPrograms.filter(p=>(activeCategory==='All'||p.category===activeCategory)&&(!activeSearch||p.title.toLowerCase().includes(activeSearch)||String(p.id).includes(activeSearch)||p.category.toLowerCase().includes(activeSearch)));const shouldShowAll=showAllPrograms||Boolean(activeSearch)||activeCategory!=='All';const list=shouldShowAll?filtered:filtered.slice(0,FEATURED_PROGRAM_COUNT);grid.innerHTML=list.map((p,i)=>`<button class="program-card" data-id="${p.id}" style="--accent:${CATEGORY_COLORS[i%CATEGORY_COLORS.length]}"><span class="num">${String(p.id).padStart(2,'0')}</span><span class="title">${esc(p.title)}</span><span class="category">${esc(p.category)}</span></button>`).join('');empty.hidden=filtered.length>0;$$('.program-card').forEach(c=>c.onclick=()=>showDetail(Number(c.dataset.id)));updateProgramViewButton(filtered.length);}
function updateProgramViewButton(total){const btn=$('#view-all-programs');if(!btn)return;const label=btn.querySelector('span');if(showAllPrograms&&!activeSearch&&activeCategory==='All'){label.textContent='Show Featured Programs';btn.setAttribute('aria-label','Show featured programs');}else{label.textContent=`View All ${total||allPrograms.length} Programs`;btn.setAttribute('aria-label',`View all ${total||allPrograms.length} programs`);}}
function showAllProgramsView(){showAllPrograms=true;activeSearch='';activeCategory='All';if(search)search.value='';renderCategories();renderPrograms();document.querySelector('#programs').scrollIntoView({behavior:'smooth',block:'start'});}
function showDetail(id){const p=allPrograms.find(x=>x.id===id);if(!p)return;const modal=document.createElement('div');modal.className='detail-modal';modal.innerHTML=`<div class="detail-box"><button class="detail-close">×</button><span class="eyebrow">Program ${String(p.id).padStart(2,'0')} · ${esc(p.category)}</span><h2>${esc(p.title)}</h2><p>${esc(p.explanation||'No explanation available.')}</p><div class="detail-code"><div><b>C CODE</b><button class="copy-detail">Copy code</button></div><pre>${esc(p.code||'No code found.')}</pre></div><div class="detail-output"><b>Sample Output</b><pre>${esc(p.output||'No output recorded.')}</pre></div></div>`;document.body.appendChild(modal);modal.querySelector('.detail-close').onclick=()=>modal.remove();modal.onclick=e=>{if(e.target===modal)modal.remove()};modal.querySelector('.copy-detail').onclick=async()=>{try{await navigator.clipboard.writeText(p.code||'');showToast('Code copied to clipboard!')}catch{showToast('Copy is not available in this browser.')}}}
function renderProblems(){$('#problem-grid').innerHTML=problems.map(x=>`<article class="problem-card"><div style="display:flex;justify-content:space-between;gap:6px"><h3>${esc(x.title)}</h3><span class="difficulty ${x.difficulty.toLowerCase()}">${esc(x.difficulty)}</span></div><p>${esc(x.description)}</p><div class="problem-foot"><span>By ${esc(x.author)}</span><span>♡ ${x.likes} &nbsp; ◌ ${x.comments}</span></div></article>`).join('')}
function renderQuestions(){$('#questions-grid').innerHTML=questions.map((q,i)=>`<article class="question"><button><span class="question-num">${String(i+1).padStart(2,'0')}</span>${esc(q.question)}<span class="chevron">⌄</span></button><div class="question-answer">${esc(q.answer)}</div></article>`).join('');$$('.question button').forEach(b=>b.onclick=()=>b.parentElement.classList.toggle('open'))}
function setupUI(){search.oninput=e=>{activeSearch=e.target.value.trim().toLowerCase();renderPrograms()};
 const langBtn=$('#language-btn'),menu=$('#language-menu');langBtn.onclick=()=>{menu.classList.toggle('open');langBtn.setAttribute('aria-expanded',menu.classList.contains('open'))};$$('.lang-option').forEach(btn=>btn.onclick=()=>setLanguage(btn.dataset.lang,btn));document.addEventListener('click',e=>{if(!e.target.closest('.language-picker'))menu.classList.remove('open')});
 $('#theme-toggle').onclick=()=>{document.body.classList.toggle('light');localStorage.setItem('c-theme',document.body.classList.contains('light')?'light':'dark');$('#theme-toggle').textContent=document.body.classList.contains('light')?'☾':'☼'};if(localStorage.getItem('c-theme')==='light'){document.body.classList.add('light');$('#theme-toggle').textContent='☾'}
 $('#mobile-menu-btn').onclick=()=>$('#main-nav').classList.toggle('open');$$('.nav-link').forEach(a=>a.onclick=()=>$('#main-nav').classList.remove('open'));
 $('#view-all-programs').onclick=()=>{showAllPrograms=!showAllPrograms;renderPrograms();if(showAllPrograms)document.querySelector('#programs').scrollIntoView({behavior:'smooth',block:'start'});};$$('[data-view-all="true"]').forEach(a=>a.addEventListener('click',e=>{e.preventDefault();showAllProgramsView();}));
 $('#problem-toast').onclick=()=>showToast('Problem browser is ready — keep practicing!');$('#interview-toast').onclick=()=>showToast('You are viewing the most important starter questions.');
}
function setLanguage(lang,btn){const t=translations[lang]||translations.en;$$('[data-i18n]').forEach(el=>{if(t[el.dataset.i18n])el.textContent=t[el.dataset.i18n]});$$('.lang-option').forEach(x=>x.classList.remove('selected'));btn.classList.add('selected');document.documentElement.lang=lang;localStorage.setItem('c-language',lang);$('#language-menu').classList.remove('open');showToast(`Language: ${btn.textContent.trim()}`)}
function observeReveal(){const io=new IntersectionObserver(es=>es.forEach(e=>{if(e.isIntersecting)e.target.classList.add('visible')}),{threshold:.08});$$('.reveal').forEach(e=>io.observe(e));}
function updateProgress(){const h=document.documentElement.scrollHeight-innerHeight;$('#scroll-progress').style.width=(h>0?(scrollY/h)*100:0)+'%';$$('.nav-link').forEach(a=>{const sec=document.querySelector(a.getAttribute('href'));if(sec){const r=sec.getBoundingClientRect();if(r.top<=110&&r.bottom>110){$$('.nav-link').forEach(n=>n.classList.remove('active'));a.classList.add('active')}}})}
window.addEventListener('scroll',updateProgress,{passive:true});
function showToast(msg){const t=$('#toast');t.textContent=msg;t.classList.add('show');clearTimeout(window.toastTimer);window.toastTimer=setTimeout(()=>t.classList.remove('show'),1900)}
function esc(s){return String(s).replace(/[&<>"']/g,m=>({'&':'&amp;','<':'&lt;','>':'&gt;','"':'&quot;',"'":'&#039;'}[m]))}
init();
/* =========================================================
   C LANGUAGE FUN FACTS
   ========================================================= */

const cFunFacts = [
  {
    icon: "🏛️",
    title: "Born at Bell Labs",
    text: "C was developed by Dennis Ritchie at Bell Labs in the early 1970s."
  },
  {
    icon: "🐧",
    title: "Linux Loves C",
    text: "A large part of the Linux kernel is written in C, making C extremely important in operating systems."
  },
  {
    icon: "🚀",
    title: "Fast & Efficient",
    text: "C is known for its speed and efficiency because it provides low-level memory access with very little runtime overhead."
  },
  {
    icon: "🌳",
    title: "A Language That Inspired Many",
    text: "C has influenced many popular programming languages, including C++, C#, Java and several others."
  },
  {
    icon: "💾",
    title: "Close to Hardware",
    text: "C gives programmers powerful control over memory, pointers and hardware-related operations."
  },
  {
    icon: "⚙️",
    title: "Still Used Today",
    text: "C continues to be widely used for embedded systems, firmware, operating systems, compilers and performance-critical software."
  }
];

let currentFact = 0;

function renderFunFact(index, animate = true) {
  const fact = cFunFacts[index];

  const card = document.querySelector(".fun-fact-card");
  const icon = document.querySelector("#fact-icon");
  const title = document.querySelector("#fact-title");
  const text = document.querySelector("#fact-text");
  const number = document.querySelector("#fact-number");
  const dots = document.querySelector("#fact-dots");

  if (!card || !icon || !title || !text || !number || !dots) return;

  if (animate) {
    card.classList.remove("fact-changing");

    // Restart CSS animation
    void card.offsetWidth;

    card.classList.add("fact-changing");
  }

  icon.textContent = fact.icon;
  title.textContent = fact.title;
  text.textContent = fact.text;

  number.textContent = String(index + 1).padStart(2, "0");

  dots.innerHTML = cFunFacts
    .map((_, i) => `
      <button
        class="fact-dot ${i === index ? "active" : ""}"
        type="button"
        aria-label="Show fact ${i + 1}"
        data-fact="${i}">
      </button>
    `)
    .join("");

  dots.querySelectorAll(".fact-dot").forEach(dot => {
    dot.addEventListener("click", () => {
      currentFact = Number(dot.dataset.fact);
      renderFunFact(currentFact);
    });
  });
}

function nextFunFact() {
  currentFact = (currentFact + 1) % cFunFacts.length;
  renderFunFact(currentFact);
}

function setupFunFacts() {
  const nextButton = document.querySelector("#next-fact");

  if (!nextButton) return;

  renderFunFact(currentFact, false);

  nextButton.addEventListener("click", nextFunFact);
}

document.addEventListener("DOMContentLoaded", setupFunFacts);

/* =========================================================
   30 DAYS C MASTERY PLAN
   ========================================================= */

const cStudyPlan = [

  {
    day: 1,
    icon: "💻",
    title: "Introduction to C",
    description: "Learn the history of C, its features, compiler and write your first C program."
  },

  {
    day: 2,
    icon: "🔢",
    title: "Variables & Data Types",
    description: "Learn int, float, char, double, constants and how data is stored."
  },

  {
    day: 3,
    icon: "⚙️",
    title: "Operators",
    description: "Master arithmetic, relational, logical, assignment and increment operators."
  },

  {
    day: 4,
    icon: "⌨️",
    title: "Input & Output",
    description: "Learn printf(), scanf() and format specifiers for taking user input."
  },

  {
    day: 5,
    icon: "🔀",
    title: "if & else",
    description: "Understand conditions, nested if statements and decision making."
  },

  {
    day: 6,
    icon: "🎛️",
    title: "switch Statement",
    description: "Learn switch, case, break and default with practical programs."
  },

  {
    day: 7,
    icon: "🧠",
    title: "Revision + Challenge",
    description: "Revise Days 1–6 and solve 10 beginner C programming problems."
  },

  {
    day: 8,
    icon: "🔁",
    title: "for Loop",
    description: "Master for loops and use them to solve counting and mathematical problems."
  },

  {
    day: 9,
    icon: "🔄",
    title: "while & do-while",
    description: "Learn condition-controlled loops and understand when to use each loop."
  },

  {
    day: 10,
    icon: "⭐",
    title: "Nested Loops & Patterns",
    description: "Create star, number and character patterns using nested loops."
  },

  {
    day: 11,
    icon: "🧩",
    title: "Functions",
    description: "Learn function declaration, definition, parameters and return values."
  },

  {
    day: 12,
    icon: "♻️",
    title: "Recursion",
    description: "Understand recursive functions, base cases and recursive problem solving."
  },

  {
    day: 13,
    icon: "📦",
    title: "Scope & Storage Classes",
    description: "Learn local, global, static, auto, register and extern concepts."
  },

  {
    day: 14,
    icon: "🧮",
    title: "Mini Project",
    description: "Build a calculator or number utility project using everything learned."
  },

  {
    day: 15,
    icon: "📚",
    title: "1D Arrays",
    description: "Learn how to store, search, sort and process multiple values using arrays."
  },

  {
    day: 16,
    icon: "🔲",
    title: "2D Arrays",
    description: "Work with matrices and learn matrix addition, multiplication and traversal."
  },

  {
    day: 17,
    icon: "🔤",
    title: "Strings",
    description: "Understand character arrays and learn how strings work in C."
  },

  {
    day: 18,
    icon: "📝",
    title: "String Functions",
    description: "Practice strlen(), strcpy(), strcat(), strcmp() and other string functions."
  },

  {
    day: 19,
    icon: "👉",
    title: "Pointers",
    description: "Understand addresses, dereferencing, pointer variables and memory."
  },

  {
    day: 20,
    icon: "🔗",
    title: "Pointers & Arrays",
    description: "Learn the relationship between pointers and arrays."
  },

  {
    day: 21,
    icon: "🎯",
    title: "Pointer Challenge",
    description: "Solve practical pointer problems and strengthen your memory concepts."
  },

  {
    day: 22,
    icon: "🏗️",
    title: "Structures",
    description: "Create custom data types and organize related information using structures."
  },

  {
    day: 23,
    icon: "🧱",
    title: "Union & Enum",
    description: "Understand unions, enumerations and their practical applications."
  },

  {
    day: 24,
    icon: "🧠",
    title: "Dynamic Memory",
    description: "Master malloc(), calloc(), realloc() and free()."
  },

  {
    day: 25,
    icon: "📁",
    title: "File Handling",
    description: "Learn how to create, read, write and append files using C."
  },

  {
    day: 26,
    icon: "⚙️",
    title: "Preprocessor & Macros",
    description: "Learn #include, #define, macros and conditional compilation."
  },

  {
    day: 27,
    icon: "💻",
    title: "Command Line Arguments",
    description: "Understand argc, argv and build programs using command-line arguments."
  },

  {
    day: 28,
    icon: "🌳",
    title: "Data Structures",
    description: "Start implementing stacks, queues and linked lists using C."
  },

  {
    day: 29,
    icon: "🚀",
    title: "Final Project",
    description: "Build a complete C programming project using your knowledge."
  },

  {
    day: 30,
    icon: "🏆",
    title: "Mastery Challenge",
    description: "Complete the final coding challenge and prepare for C programming interviews."
  }

];


let currentStudyDay = 0;


/* Completed days */

let completedStudyDays = JSON.parse(
  localStorage.getItem("cStudyCompletedDays") || "[]"
);


/* Render current day */

function renderStudyDay(animate = true) {

  const day = cStudyPlan[currentStudyDay];

  const number = document.getElementById("study-day-number");
  const icon = document.getElementById("study-day-icon");
  const title = document.getElementById("study-day-title");
  const description = document.getElementById("study-day-description");

  const counter = document.getElementById("study-day-counter");
  const navigation = document.getElementById("study-navigation-text");

  const progress = document.getElementById("study-progress-fill");

  const previous = document.getElementById("previous-study-day");
  const next = document.getElementById("next-study-day");

  const complete = document.getElementById("complete-study-day");

  const card = document.querySelector(".study-day-card");


  if (!day) return;


  /* Animation */

  if (animate && card) {

    card.classList.remove("day-changing");

    void card.offsetWidth;

    card.classList.add("day-changing");

  }


  /* Content */

  number.textContent =
    `DAY ${String(day.day).padStart(2, "0")}`;

  icon.textContent = day.icon;

  title.textContent = day.title;

  description.textContent = day.description;


  counter.textContent =
    `Day ${day.day} of 30`;

  navigation.textContent =
    `Day ${day.day} / 30`;


  /* Progress */

  progress.style.width =
    `${((currentStudyDay + 1) / 30) * 100}%`;


  /* Navigation */

  previous.disabled =
    currentStudyDay === 0;

  next.disabled =
    currentStudyDay === cStudyPlan.length - 1;


  /* Complete button */

  if (completedStudyDays.includes(currentStudyDay)) {

    complete.textContent = "✓ Day Completed";

    complete.classList.add("completed");

  } else {

    complete.textContent = "✓ Mark Day Complete";

    complete.classList.remove("completed");

  }

}


/* Next */

function nextStudyDay() {

  if (currentStudyDay < cStudyPlan.length - 1) {

    currentStudyDay++;

    renderStudyDay();

  }

}


/* Previous */

function previousStudyDay() {

  if (currentStudyDay > 0) {

    currentStudyDay--;

    renderStudyDay();

  }

}


/* Complete */

function completeCurrentStudyDay() {

  if (completedStudyDays.includes(currentStudyDay)) {

    completedStudyDays =
      completedStudyDays.filter(
        day => day !== currentStudyDay
      );

  } else {

    completedStudyDays.push(currentStudyDay);

  }


  localStorage.setItem(
    "cStudyCompletedDays",
    JSON.stringify(completedStudyDays)
  );


  renderStudyDay(false);

}


/* Setup */

function setupStudyPlan() {

  const next =
    document.getElementById("next-study-day");

  const previous =
    document.getElementById("previous-study-day");

  const complete =
    document.getElementById("complete-study-day");


  if (!next || !previous || !complete) return;


  next.addEventListener(
    "click",
    nextStudyDay
  );


  previous.addEventListener(
    "click",
    previousStudyDay
  );


  complete.addEventListener(
    "click",
    completeCurrentStudyDay
  );


  renderStudyDay(false);

}


document.addEventListener(
  "DOMContentLoaded",
  setupStudyPlan
);
/* =========================================================
   C MAGIC TRICKS
   ========================================================= */

const cMagicTricks = [

  {
    icon: "⚡",
    title: "Swap Two Numbers Without a Third Variable",
    description: "You can swap two integer values using arithmetic operations.",
    code: `a = a + b;
b = a - b;
a = a - b;`
  },

  {
    icon: "🔢",
    title: "Check Even or Odd Like a Pro",
    description: "Use the modulus operator to instantly determine whether a number is even or odd.",
    code: `if (n % 2 == 0)
    printf("Even");
else
    printf("Odd");`
  },

  {
    icon: "🎯",
    title: "Find the Last Digit",
    description: "The modulus operator gives you the last digit of an integer.",
    code: `int last = n % 10;
printf("%d", last);`
  },

  {
    icon: "🚀",
    title: "Shortcut for Incrementing",
    description: "Instead of writing n = n + 1, C gives you a shorter and cleaner way.",
    code: `n++;
/* Same as:
   n = n + 1;
*/`
  },

  {
    icon: "🧠",
    title: "Reverse a Number",
    description: "Use division and modulus inside a loop to reverse the digits of a number.",
    code: `rev = 0;

while (n != 0) {
    rev = rev * 10 + n % 10;
    n = n / 10;
}`
  },

  {
    icon: "💡",
    title: "Array Size Trick",
    description: "You can calculate the number of elements in an array using sizeof.",
    code: `int arr[] = {10, 20, 30, 40};

int size = sizeof(arr) / sizeof(arr[0]);`
  },

  {
    icon: "🔗",
    title: "Access Value Through a Pointer",
    description: "The * operator lets you access the value stored at a memory address.",
    code: `int x = 10;
int *p = &x;

printf("%d", *p);`
  },

  {
    icon: "🏆",
    title: "The Famous C Hello World",
    description: "The classic first step of almost every C programmer.",
    code: `#include <stdio.h>

int main() {
    printf("Hello, World!");
    return 0;
}`
  }

];


let currentMagic = 0;


function renderMagicTrick(animate = true) {

  const trick = cMagicTricks[currentMagic];

  const number =
    document.getElementById("magic-number");

  const symbol =
    document.getElementById("magic-symbol");

  const title =
    document.getElementById("magic-title");

  const description =
    document.getElementById("magic-description");

  const code =
    document.getElementById("magic-code");

  const dots =
    document.getElementById("magic-dots");

  const card =
    document.querySelector(".magic-card");


  if (!trick) return;


  if (animate && card) {

    card.style.animation = "none";

    void card.offsetWidth;

    card.style.animation =
      "factChange .35s ease";

  }


  number.textContent =
    `TRICK ${String(currentMagic + 1).padStart(2, "0")}`;

  symbol.textContent =
    trick.icon;

  title.textContent =
    trick.title;

  description.textContent =
    trick.description;

  code.textContent =
    trick.code;


  dots.innerHTML =
    cMagicTricks.map((_, index) => `

      <button
        class="magic-dot ${index === currentMagic ? "active" : ""}"
        data-magic="${index}"
        type="button"
        aria-label="Show magic trick ${index + 1}">
      </button>

    `).join("");


  dots.querySelectorAll(".magic-dot")
    .forEach(dot => {

      dot.addEventListener("click", () => {

        currentMagic =
          Number(dot.dataset.magic);

        renderMagicTrick();

      });

    });

}


function nextMagicTrick() {

  currentMagic =
    (currentMagic + 1) %
    cMagicTricks.length;

  renderMagicTrick();

}


function setupMagicTricks() {

  const next =
    document.getElementById("next-magic");

  const copy =
    document.getElementById("copy-magic-code");


  if (!next) return;


  renderMagicTrick(false);


  next.addEventListener(
    "click",
    nextMagicTrick
  );


  if (copy) {

    copy.addEventListener(
      "click",
      async () => {

        const code =
          document.getElementById("magic-code").textContent;

        try {

          await navigator.clipboard.writeText(code);

          copy.textContent =
            "✓ Copied!";

          setTimeout(() => {

            copy.textContent =
              "📋 Copy";

          }, 1500);

        } catch (error) {

          copy.textContent =
            "Copy failed";

        }

      }
    );

  }

}


document.addEventListener(
  "DOMContentLoaded",
  setupMagicTricks
);