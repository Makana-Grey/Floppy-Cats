import Koa from 'koa'
import { koaBody } from 'koa-body'

import routes from './routes.js'

const app = new Koa()

app.use(koaBody())
app.use(routes)

app.listen(3000)
