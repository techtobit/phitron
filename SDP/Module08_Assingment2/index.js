let videos=[]

const buttons = document.querySelectorAll("button");
const sortBtn = document.getElementById('sort_view')

videos = new Proxy([], {
  set(target, property, value) {
    target[property] = value;
    displayData(target); 
    return true;
  }
});

document.addEventListener('DOMContentLoaded', () => {
	buttons.forEach(button => {
		button.addEventListener("click", (event) => {
			buttons.forEach(btn => btn.classList.remove("bg-red-600"));
			event.target.classList.add("bg-red-600");
			const categoryId = event.target.getAttribute("data-id");
			fetchData(categoryId);
		});
	});
});


function fetchData(categoryId) {
	
	fetch(`https://openapi.programming-hero.com/api/videos/category/${categoryId} `)
		.then(res => res.json())
		.then(data => {
			videos.splice(0, videos.length, ...data.data);
		})
		.catch(error => console.log(error))
}


function formatTime(seconds) {
  const hours = Math.floor(seconds / 3600);
  const minutes = Math.floor((seconds % 3600) / 60);
  return `${hours}hrs ${minutes}min ago`;
}



sortBtn.addEventListener('click', ()=>{

	const shortedVideo = [...videos].sort((a, b) => {
		const viewsA =  parseInt(a.others.views.replace(/[^\d]/g, ''))
		
		const viewsB =  parseInt(b.others.views.replace(/[^\d]/g, ''))
		return viewsB - viewsA;
	});
	videos = shortedVideo; 
  displayData(shortedVideo); 
  console.log('shortedVide', shortedVideo);

});





function displayData(videos) {
	console.log('videos', videos);
	
	const container = document.getElementById('video_section')
	const noContent = document.getElementById('no_content')
	
	

	// if (videos.length === 0) {
	// 	noContent.classList.remove('hidden')
	// }
	// else {
	// 	noContent.classList.add('hidden')
	// }

	noContent.classList.toggle('hidden', videos.length !== 0);

	container.innerHTML = ''
	videos.forEach(video => {
		const createdDiv = document.createElement('div')
		createdDiv.className = 'card'
		const postedTime = formatTime(video.others.posted_date);
		console.log(video.title);
		createdDiv.innerHTML = `
		
			<div class="!w-64 pt-10 !relative ">
			<div class='!relative '>
			<img class=" !h-[160px] !w-64 rounded-lg object-cover object-center" src="${video.thumbnail}" alt="">
					<div class='!absolute  z-20 right-2 bottom-[6rem]' >
						<p class="text-slate-700 bg-slate-700 text-white rounded-md px-[2px] ">${postedTime}</p>
					</div>
					<div class="flex pt-4  gap-4">
						<div class="w-10 h-10 rounded-full">
							<img class="w-10 h-10 object-cover rounded-full" src="${video.authors[0].profile_picture}" alt="">
						</div>
						<div class="" >
							<p class="text-[#171717] font-bold text-base">${video.title}</p>
							<p class="text-slate-700">${video.authors[0].profile_name} 
							<span>${video.authors[0].verified ? `<img src='./assets/verifedIcon.png' alt="Verified" class="inline-block w-4 h-4" />` : ''}</span>
							</p>
							<p class="text-slate-700">${video.others.views} views</p>
						</div>
					</div>
				</div>
			<div>
    `;
		container.appendChild(createdDiv);

	});
}




